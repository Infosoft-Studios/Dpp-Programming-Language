# Kernel & Runtime Model

The D++ Kernel & Runtime Model defines how programs interact with system‑level components, how protected execution is enforced, and how kernel directives are validated and executed.  
D++ inherits Rust’s safety‑oriented philosophy but extends it with explicit kernel‑bound constructs, protected blocks, and structured termination markers.

The runtime is designed for deterministic behavior, strict namespace resolution, and controlled privilege elevation.

---

## 1. Protected Execution Model

Protected execution is a core concept in D++.  
Any function marked with `: protected` runs inside a controlled environment where:

- kernel directives are validated  
- memory access is restricted  
- namespace resolution is locked  
- runtime state is monitored  
- termination markers are required  

Example:

```dpp
fn::secure_boot -> created(Session): protected {
    kernel::session.open: krnl.auth;
    kernel::runtime.lock: krnl.guard;

    end::line* protected
}
```

Protected blocks **must** end with:

```
end::line* protected
```

This ensures the runtime can safely unwind the block and finalize kernel interactions.

---

## 2. Kernel Directive Model

Kernel directives use the `kernel::` namespace and follow a strict binding pattern:

```
kernel::operation: krnl.action;
```

The left side (`kernel::operation`) declares the intent.  
The right side (`krnl.action`) declares the execution binding.

Examples:

```dpp
kernel::distribution.init: krnl.start;
kernel::drivers.load: krnl.bind;
kernel::runtime.sync: krnl.exec;
kernel::session.close: krnl.terminate;
```

Kernel directives always run under protected mode unless explicitly marked:

```
kernelbound
```

Example:

```dpp
fn::driver_init -> created(Driver): kernelbound {
    kernel::drivers.initialize: krnl.bind;
    end::line* kernelbound
}
```

---

## 3. Runtime Lifecycle

The D++ runtime follows a predictable lifecycle:

1. **Namespace Resolution**  
   All `using` imports are validated and locked.

2. **Privilege Context Setup**  
   Protected or kernelbound modes are activated.

3. **Directive Validation**  
   Kernel calls are checked for correctness and safety.

4. **Execution Phase**  
   The function body runs with deterministic behavior.

5. **Termination Marker Enforcement**  
   The runtime requires `end::line*` to finalize the block.

6. **State Finalization**  
   Kernel sessions, drivers, and distributions are closed or synced.

Example of a full lifecycle function:

```dpp
using system.kernel.runtime;
using system.kernel.distribution;

fn::boot_sequence -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    kernel::runtime.sync: krnl.exec;
    kernel::drivers.load: krnl.bind;

    end::line* protected
}
```

---

## 4. Runtime States

The D++ runtime operates in one of three states:

### **1. userland**
Normal execution with full Rust‑keyword support.

### **2. protected**
Restricted execution with kernel validation.

### **3. kernelbound**
Direct kernel interaction with elevated privileges.

Example:

```dpp
fn::update -> created(State): protected {
    kernel::runtime.sync: krnl.exec;
    end::line* protected
}

fn::patch_driver -> created(Driver): kernelbound {
    kernel::drivers.patch: krnl.modify;
    end::line* kernelbound
}
```

---

## 5. Error & Fault Handling

D++ uses Rust‑style error handling (`Result`, `Option`, `match`) but extends it with kernel‑level faults:

```
KernelFault::AccessDenied
KernelFault::InvalidDirective
KernelFault::RuntimeViolation
KernelFault::TerminationMissing
```

Example:

```dpp
fn::session_open -> created(Result<Session, KernelFault>): protected {
    kernel::session.open: krnl.auth;

    match kernel::session.status {
        Ok(s) => return s,
        Err(e) => return e,
    }

    end::line* protected
}
```

---

## 6. Termination Marker Semantics

The termination marker:

```
end::line* <mode>
```

is mandatory for:

- protected blocks  
- kernelbound blocks  
- any function containing kernel directives  

It signals:

- privilege drop  
- runtime finalization  
- directive flush  
- safe block closure  

Example:

```dpp
fn::shutdown -> created(Void): protected {
    kernel::runtime.stop: krnl.exec;
    kernel::session.close: krnl.terminate;

    end::line* protected
}
```

---

This Kernel & Runtime Model defines how D++ interacts with system‑level components, ensuring deterministic behavior, strict safety, and expressive control over protected and kernelbound execution.
