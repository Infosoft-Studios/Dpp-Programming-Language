# D++ Language Specification

The D++ Language Specification defines the core syntax, structural rules, and execution semantics of the D++ programming language.  
D++ inherits the full keyword set of Rust, ensuring expressive, modern, and safe systems‑level development.  
On top of Rust’s foundation, D++ introduces additional system‑focused keywords and constructs for protected execution, kernel directives, and hierarchical namespace control.

---

## 1. File Structure

D++ source files use the `.dpp` extension and consist of:

- namespace imports  
- function declarations  
- kernel directives  
- protected blocks  
- termination markers  

Example:

```dpp
using system.kernel.runtime;
using system.windows.core;

fn::boot -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    end::line* protected
}
```

---

## 2. Namespace Imports

Namespaces in D++ follow a deep hierarchical structure.  
Imports use the `using` keyword:

```
using system.windows.winv.ver.wmsdos.win32.api;
using system.config.win.win32.api.server;
using system.windows.msdos;
```

Namespaces always resolve left‑to‑right, representing:

- system domain  
- subsystem  
- version  
- distribution  
- API layer  

---

## 3. Function Declaration Syntax

D++ functions use a structured declaration format:

```
fn::name -> created(Type): modifier {
    ...
    end::line* modifier
}
```

### Components

- `fn::name`  
  Declares a function with explicit intent.

- `-> created(Type)`  
  Defines the return binding or creation type.

- `: modifier`  
  Specifies execution mode (e.g., `protected`, `public`, `kernelbound`).

- `{ ... }`  
  Function body.

- `end::line* modifier`  
  Required termination marker for protected or kernel‑bound blocks.

Example:

```dpp
fn::load -> created(Main): protected {
    kernel::drivers.initialize: krnl.load;
    end::line* protected
}
```

---

## 4. Kernel Directives

Kernel operations use the `kernel::` namespace and follow a binding pattern:

```
kernel::operation: krnl.action;
```

Examples:

```dpp
kernel::loaddistrubution: krnl.load;
kernel::runtime.start: krnl.exec;
kernel::drivers.initialize: krnl.bind;
```

Kernel directives always execute under protected mode unless explicitly overridden.

---

## 5. Protected Blocks

Protected blocks enforce controlled execution and must end with:

```
end::line* protected
```

Rules:

- Protected blocks cannot return unmanaged types.  
- Kernel directives inside protected blocks must be validated by the runtime.  
- Nested protected blocks are allowed but must terminate independently.

Example:

```dpp
fn::secure -> created(Session): protected {
    kernel::session.open: krnl.auth;
    end::line* protected
}
```

---

## 6. Comments

D++ supports two comment styles:

### Single‑line
```
# This is a comment
```

### Multi‑line
```
#{
   Multi‑line comment block
}#
```

---

## 7. Reserved Keywords

### Rust Keywords (inherited by D++)
D++ includes **all Rust keywords**, such as:

```
fn, let, mut, const, static, match, enum, struct, impl,
trait, mod, use, pub, crate, super, self, loop, while,
for, if, else, return, break, continue, async, await,
move, unsafe, extern, type, where, dyn, ref
```

### Additional D++ Keywords
D++ adds system‑level keywords not found in Rust:

```
fn::
created
protected
kernel
end::line*
distribution
runtime
drivers
session
kernelbound
```

These keywords define D++’s unique system‑execution model.

---

This specification defines the core rules of D++ syntax and execution behavior.  
All further documentation builds upon these foundational structures.
