# Examples & Tutorials

This section provides practical examples and guided tutorials demonstrating how to write real D++ programs.  
All examples use the D++ syntax, the US Compiler (Ultra‑Speed Compiler), protected execution, kernel directives, and hierarchical namespaces.

These examples are designed to help new developers understand the structure, flow, and behavior of D++ code.

---

# 1. Basic Program

A minimal D++ program showing namespace imports, a protected function, and a kernel directive.

```dpp
using system.kernel.runtime;

fn::hello_world -> created(Void): protected {
    kernel::runtime.sync: krnl.exec;
    end::line* protected
}
```

This example demonstrates:

- basic namespace import  
- protected execution  
- a simple kernel directive  
- correct termination marker  

---

# 2. Boot Sequence Example

A realistic system‑level boot sequence using multiple namespaces.

```dpp
using system.kernel.runtime;
using system.kernel.distribution;
using system.kernel.drivers;

fn::boot_sequence -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    kernel::drivers.initialize: krnl.bind;
    kernel::runtime.sync: krnl.exec;

    end::line* protected
}
```

This example shows:

- multi‑namespace imports  
- chained kernel directives  
- protected block behavior  
- deterministic runtime flow  

---

# 3. Kernelbound Driver Patch

A function running in elevated privilege mode.

```dpp
using system.kernel.drivers;

fn::patch_driver -> created(Driver): kernelbound {
    kernel::drivers.patch: krnl.modify;
    kernel::drivers.load: krnl.bind;

    end::line* kernelbound
}
```

This example demonstrates:

- kernelbound execution  
- driver patching  
- elevated privilege rules  
- kernelbound termination marker  

---

# 4. Legacy Subsystem Execution (MSDOS)

A D++ function interacting with a legacy subsystem.

```dpp
using system.windows.msdos;

fn::legacy_exec -> created(Session): protected {
    kernel::msdos.exec: krnl.call;
    kernel::msdos.interrupt: krnl.signal;

    end::line* protected
}
```

This example shows:

- legacy subsystem access  
- DOS‑style operations  
- protected execution rules  

---

# 5. Server Deployment Example

A server deployment routine using the Win32 API server namespace.

```dpp
using system.config.win.win32.api.server;

fn::deploy_server -> created(Server): protected {
    kernel::server.config: krnl.prepare;
    kernel::server.deploy: krnl.exec;

    end::line* protected
}
```

This example demonstrates:

- server configuration  
- deployment directives  
- protected execution  

---

# 6. Tutorial: Writing Your First Protected Function

### Step 1 — Import a namespace

```dpp
using system.kernel.runtime;
```

### Step 2 — Declare a protected function

```dpp
fn::start -> created(Main): protected {
```

### Step 3 — Add a kernel directive

```dpp
    kernel::runtime.start: krnl.exec;
```

### Step 4 — End with a termination marker

```dpp
    end::line* protected
}
```

### Final Result

```dpp
using system.kernel.runtime;

fn::start -> created(Main): protected {
    kernel::runtime.start: krnl.exec;
    end::line* protected
}
```

---

# 7. Tutorial: Creating a Kernelbound Function

### Step 1 — Import kernel drivers

```dpp
using system.kernel.drivers;
```

### Step 2 — Declare a kernelbound function

```dpp
fn::driver_update -> created(Driver): kernelbound {
```

### Step 3 — Add privileged kernel directives

```dpp
    kernel::drivers.patch: krnl.modify;
    kernel::drivers.load: krnl.bind;
```

### Step 4 — End with kernelbound termination

```dpp
    end::line* kernelbound
}
```

### Final Result

```dpp
using system.kernel.drivers;

fn::driver_update -> created(Driver): kernelbound {
    kernel::drivers.patch: krnl.modify;
    kernel::drivers.load: krnl.bind;
    end::line* kernelbound
}
```

---

# 8. Full System Example

A complete D++ program demonstrating multiple subsystems working together.

```dpp
using system.kernel.runtime;
using system.kernel.distribution;
using system.kernel.drivers;
using system.windows.msdos;

fn::system_boot -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    kernel::drivers.initialize: krnl.bind;
    kernel::runtime.sync: krnl.exec;
    kernel::msdos.exec: krnl.call;

    end::line* protected
}
```

This example shows:

- multi‑namespace imports  
- protected execution  
- kernelbound‑compatible directives  
- legacy subsystem integration  
- deterministic boot flow  

---

This Examples & Tutorials section provides practical guidance for writing real D++ programs using the US Compiler and the D++ Standard Library.
