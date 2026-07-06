# Appendix & Grammar Specification (D++ 1.0)

This appendix provides the formal grammar, keyword list, version notes, and structural definitions for the D++ programming language.  
It serves as the authoritative reference for the US Compiler (Ultra‑Speed Compiler), ensuring consistent parsing, validation, and execution across all D++ environments.

---

# 1. Formal Grammar (EBNF)

Below is the official D++ grammar in Extended Backus–Naur Form (EBNF).  
This grammar defines how the US Compiler interprets `.dpp` source files.

```
Program          = { Import }, { FunctionDecl } ;

Import           = "using", Namespace, ";" ;
Namespace        = Identifier, { ".", Identifier } ;

FunctionDecl     = "fn::", Identifier, "->", "created", "(", Type, ")",
                   ":", Mode, Block ;

Mode             = "protected" | "kernelbound" | "public" | "userland" ;

Block            = "{", { Statement }, Terminator, "}" ;

Terminator       = "end::line*", Mode ;

Statement        = KernelDirective, ";" 
                 | RustStatement
                 | Comment ;

KernelDirective  = "kernel::", Identifier, ":", "krnl.", Identifier ;

RustStatement    = any valid Rust statement (let, match, loop, etc.) ;

Comment          = "#" , { any character }
                 | "#{" , { any character }, "}#" ;

Identifier       = letter, { letter | digit | "_" } ;
Type             = Identifier ;
```

This grammar ensures:

- deterministic parsing  
- strict namespace resolution  
- mandatory termination markers  
- kernel‑aware validation  
- full Rust keyword compatibility  

---

# 2. Keyword Reference

## Rust Keywords (Inherited)

D++ includes **all Rust keywords**, such as:

```
fn, let, mut, const, static, match, enum, struct, impl,
trait, mod, use, pub, crate, super, self, loop, while,
for, if, else, return, break, continue, async, await,
move, unsafe, extern, type, where, dyn, ref
```

These keywords behave identically to Rust inside `userland` mode.

---

## D++‑Specific Keywords (Added)

D++ introduces additional system‑level keywords:

```
fn::
created
protected
kernel
kernelbound
end::line*
distribution
runtime
drivers
session
msdos
```

These keywords define D++’s protected execution model, kernel directive system, and namespace hierarchy.

---

# 3. Reserved Namespace Roots

The following namespace roots are reserved for system‑level modules:

```
system.kernel
system.windows
system.config
system.runtime
system.session
system.distribution
system.windows.msdos
```

User‑defined namespaces may not override these roots.

---

# 4. Version Notes (D++ 1.0)

### Introduced in D++ 1.0:

- US Compiler (Ultra‑Speed Compiler)  
- Protected execution model  
- Kernelbound privilege mode  
- Structured termination markers  
- Deep namespace chains  
- Kernel directive binding system  
- Rust keyword inheritance  
- D++ standard library  
- D++ IR (US‑IR)  
- Distribution‑aware runtime  

---

# 5. Error & Fault Types

The US Compiler and runtime may emit the following fault types:

```
NamespaceError::UnresolvedPath
KernelFault::PrivilegeViolation
KernelFault::InvalidDirective
KernelFault::TerminationMissing
KernelFault::RuntimeViolation
KernelFault::AccessDenied
```

These faults ensure safe, deterministic execution.

---

# 6. Example: Grammar‑Compliant D++ Function

```dpp
using system.kernel.runtime;
using system.kernel.distribution;

fn::boot -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    kernel::runtime.sync: krnl.exec;

    end::line* protected
}
```

This example satisfies:

- EBNF grammar  
- namespace rules  
- protected execution rules  
- kernel directive structure  
- termination marker requirements  

---

# 7. Example: Kernelbound Grammar Demonstration

```dpp
using system.kernel.drivers;

fn::driver_update -> created(Driver): kernelbound {
    kernel::drivers.patch: krnl.modify;
    kernel::drivers.load: krnl.bind;

    end::line* kernelbound
}
```

This example demonstrates:

- kernelbound mode  
- privileged kernel directives  
- correct termination marker  
- valid namespace resolution  

---

# 8. Future Extensions (Planned for D++ 1.1+)

Planned additions include:

- async protected blocks  
- kernel event listeners  
- distribution metadata reflection  
- US‑IR optimization layers  
- multi‑target compilation  
- protected trait implementations  
- kernelbound structs  

These features will extend D++ while maintaining strict grammar consistency.

---

This Appendix & Grammar Specification defines the formal structure of D++ 1.0, ensuring that all compilers, runtimes, and tools interpret the language consistently and safely.
