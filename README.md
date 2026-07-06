# D++ — Ultra‑Speed System Language  
A modern, kernel‑aware, protected‑execution programming language built from **C + C++ + ASM**, powered by the **US Compiler (Ultra‑Speed Compiler)**.

D++ is designed for OS developers, kernel engineers, runtime architects, and system creators who need **deterministic execution**, **deep namespace control**, and **safe privilege modes** — without sacrificing raw performance.

---

## 📦 Features

### Ultra‑Speed Compiler (US Compiler)
The US Compiler is built directly into the D++ runtime. It performs:

- Hyper‑lexing  
- Fast‑parse AST construction  
- Instant namespace resolution  
- Privilege‑mode analysis  
- Kernel directive validation  
- US‑IR generation  
- Direct execution  

Compilation happens in **milliseconds**, even for system‑level code.

---

### Protected Execution Model
Protected mode ensures safe system interaction:

```dpp
fn::boot -> created(Main): protected {
    kernel::runtime.sync: krnl.exec;
    end::line* protected
}
```

Protected mode enforces:

- Safe memory access  
- Validated kernel directives  
- Deterministic runtime behavior  
- Mandatory termination markers  

---

### Kernelbound Mode
Kernelbound mode gives D++ direct kernel authority:

```dpp
fn::patch_driver -> created(Driver): kernelbound {
    kernel::drivers.patch: krnl.modify;
    end::line* kernelbound
}
```

Used for:

- Driver patching  
- Distribution loading  
- Runtime modification  
- Hardware‑level operations  

---

### Deep Namespace Hierarchy
D++ uses structured namespaces that mirror real OS architecture:

```
using system.windows.winv.ver.wmsdos.win32.api;
using system.kernel.runtime;
using system.kernel.distribution;
using system.windows.msdos;
```

This creates clarity and prevents collisions.

---

## 🏗️ Architecture Overview

### Runtime Modes
- **userland** — Rust‑style safe code  
- **protected** — guarded system code  
- **kernelbound** — privileged kernel code  

### US‑IR (Ultra‑Speed Intermediate Representation)
The US Compiler generates a structured IR:

```
USIRFunction {
    name: "boot",
    mode: Protected,
    ops: [
        USIRKernelCall { op: "distribution.init", action: "start" },
        USIRKernelCall { op: "runtime.sync", action: "exec" }
    ],
    terminator: ProtectedTerminator
}
```

---

## 📚 Syntax Overview

### Function Declaration

```dpp
fn::name -> created(Type): protected {
    kernel::runtime.sync: krnl.exec;
    end::line* protected
}
```

### Kernel Directives

```dpp
kernel::drivers.initialize: krnl.bind;
kernel::distribution.init: krnl.start;
kernel::runtime.sync: krnl.exec;
```

Kernel directives are **declarative**, not imperative — making system code readable and safe.

---

## 🧩 Examples

### Boot Sequence

```dpp
using system.kernel.runtime;
using system.kernel.distribution;

fn::boot_sequence -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    kernel::runtime.sync: krnl.exec;
    end::line* protected
}
```

---

### Driver Patch

```dpp
using system.kernel.drivers;

fn::patch_driver -> created(Driver): kernelbound {
    kernel::drivers.patch: krnl.modify;
    kernel::drivers.load: krnl.bind;
    end::line* kernelbound
}
```

---

### Legacy Subsystem (MSDOS)

```dpp
using system.windows.msdos;

fn::legacy_exec -> created(Session): protected {
    kernel::msdos.exec: krnl.call;
    kernel::msdos.interrupt: krnl.signal;
    end::line* protected
}
```

---

## ⚙️ Configuration

### Environment‑Style Variables (Dockur‑Inspired)

```
DPP_MODE=protected
DPP_COMPILER=us
DPP_NAMESPACE_DEPTH=6
DPP_KERNEL_ACCESS=true
DPP_RUNTIME_GUARD=strict
```

### Notes

> ⚠️ **Kernelbound mode requires elevated privileges.**  
> ⚠️ **Protected mode must always end with a termination marker.**  
> ⚠️ **Namespace resolution is strict and hierarchical.**

---

## 🛠️ Advanced Features

### Runtime Guard
Ensures:

- Privilege enforcement  
- Kernel directive validation  
- Safe block closure  
- Deterministic execution  

### Namespace Resolver
D++ resolves namespaces at ultra‑speed:

```
using system.kernel.runtime;
using system.kernel.distribution;
using system.windows.msdos;
```

If any segment is missing, the compiler throws:

```
NamespaceError::UnresolvedPath
```

---

## 🧯 Troubleshooting

### ❌ Missing termination marker

```
KernelFault::TerminationMissing
```

### ❌ Invalid kernel directive

```
KernelFault::InvalidDirective
```

### ❌ Privilege violation

```
KernelFault::PrivilegeViolation
```

---

## 🗺️ Roadmap (D++ 1.1+)

- Async protected blocks  
- Kernel event listeners  
- Distribution metadata reflection  
- US‑IR optimization layers  
- Multi‑target compilation  
- Protected trait implementations  
- Kernelbound structs  

### Current version:
Version 1.0.2

---

## ❤️ Created by Infosoft(sa)
(C) infosoft(sa) program

