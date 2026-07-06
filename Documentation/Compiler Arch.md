# Compiler Architecture (US Compiler — Ultra‑Speed Compiler)

The D++ Compiler Architecture is built around the **US Compiler**, the Ultra‑Speed Compiler.  
Unlike traditional compilers that exist as external tools, the US Compiler is **built directly into the D++ runtime**, enabling extremely fast compilation, instant namespace resolution, and near‑zero overhead kernel directive validation.

The US Compiler is designed for deterministic behavior, strict safety guarantees, and ultra‑fast system‑level execution.

---

# 1. Ultra‑Speed Compilation Pipeline

The US Compiler follows an optimized multi‑stage pipeline:

1. **Hyper‑Lexing**  
   Tokenizes `.dpp` files using a high‑speed lexical engine.

2. **Fast‑Parse AST Construction**  
   Builds the Abstract Syntax Tree with minimal overhead.

3. **Instant Namespace Resolution**  
   All `using` imports are resolved and locked in microseconds.

4. **Privilege Mode Analysis**  
   Determines execution mode (`userland`, `protected`, `kernelbound`).

5. **Kernel Directive Validation**  
   Ensures all `kernel::operation: krnl.action` pairs are legal and safe.

6. **Termination Marker Enforcement**  
   Confirms protected/kernelbound blocks end with `end::line* <mode>`.

7. **US‑IR Generation**  
   Produces Ultra‑Speed Intermediate Representation.

8. **Direct Execution / JIT / Distribution Binding**  
   Runs the IR through the D++ runtime with ultra‑low latency.

The US Compiler is designed to compile even complex system‑level programs in milliseconds.

---

# 2. Hyper‑Lexing & Tokenization

The US Compiler’s lexer recognizes:

- Rust keywords  
- D++ keywords  
- namespace chains  
- kernel directives  
- termination markers  
- identifiers  
- literals  

Example tokens:

```
fn::, boot, ->, created, (, Main, ), :, protected,
kernel::distribution.init, :, krnl.start, ;, end::line*, protected
```

---

# 3. Fast‑Parse AST Construction

The US Compiler builds a structured AST optimized for kernel‑aware execution.

Example conceptual AST:

```
FunctionDecl {
    name: "boot",
    return: "Main",
    mode: Protected,
    body: [
        KernelDirective { op: "distribution.init", action: "start" },
        KernelDirective { op: "runtime.sync", action: "exec" }
    ],
    terminator: ProtectedTerminator
}
```

---

# 4. Instant Namespace Resolution

The US Compiler resolves namespaces at ultra‑speed:

```dpp
using system.kernel.runtime;
using system.kernel.distribution;
using system.windows.msdos;
```

If any segment is missing, the compiler throws:

```
NamespaceError::UnresolvedPath
```

Resolution is deterministic and cached for future runs.

---

# 5. Privilege Mode Analysis

The US Compiler determines execution mode based on modifiers:

### userland  
Default Rust‑style execution.

### protected  
Restricted execution requiring termination markers.

### kernelbound  
Elevated privilege mode for direct kernel interaction.

Example:

```dpp
fn::driver_init -> created(Driver): kernelbound {
    kernel::drivers.initialize: krnl.bind;
    end::line* kernelbound
}
```

---

# 6. Kernel Directive Validation

Kernel directives follow:

```
kernel::<operation>: krnl.<action>;
```

The US Compiler checks:

- operation exists  
- action is valid  
- privilege mode allows the directive  
- directive is safe in the current runtime state  

Invalid directive example:

```dpp
fn::test -> created(Void) {
    kernel::runtime.sync: krnl.exec;  # illegal in userland
}
```

Compiler error:

```
KernelFault::PrivilegeViolation
```

---

# 7. Termination Marker Enforcement

Protected and kernelbound blocks **must** end with:

```
end::line* <mode>
```

Example:

```dpp
fn::secure -> created(Session): protected {
    kernel::session.open: krnl.auth;
    end::line* protected
}
```

Missing termination marker triggers:

```
KernelFault::TerminationMissing
```

---

# 8. US‑IR (Ultra‑Speed Intermediate Representation)

The US Compiler produces a highly optimized IR:

```
USIRFunction {
    name: "boot_sequence",
    mode: Protected,
    ops: [
        USIRKernelCall { op: "distribution.init", action: "start" },
        USIRKernelCall { op: "runtime.sync", action: "exec" }
    ],
    terminator: ProtectedTerminator
}
```

US‑IR is designed for ultra‑fast execution and minimal runtime overhead.

---

# 9. Direct Execution & Distribution Binding

The US Compiler binds IR directly to the runtime:

- userland → standard execution  
- protected → guarded execution  
- kernelbound → privileged kernel execution  

Example:

```dpp
using system.kernel.runtime;
using system.kernel.distribution;

fn::boot_sequence -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    kernel::runtime.sync: krnl.exec;

    end::line* protected
}
```

The US Compiler compiles and executes this in milliseconds.

---

This updated Compiler Architecture section defines how the **US Compiler (Ultra‑Speed Compiler)** transforms D++ code into safe, deterministic, kernel‑aware execution with extremely high performance.
