# Getting Started with D++

This section provides the essential steps for beginning with the D++ programming language.  
D++ is designed for system‑level development, protected execution, and structured namespace usage.  
Even in its early versions, the workflow remains simple and predictable.

---

## Installation

D++ can be used in two ways:

### 1. Source‑based usage  
You may compile D++ source files using the reference compiler or interpreter provided in the D++ toolchain.  
The toolchain follows a predictable pipeline:

- Parse  
- Validate  
- Kernel‑bind  
- Execute  

### 2. Embedded usage  
D++ modules can be embedded into system distributions that support D++ runtime execution.  
This allows direct interaction with kernel‑level namespaces and protected blocks.

---

## Creating Your First D++ File

D++ files use the `.dpp` extension:

```
main.dpp
```

A minimal program looks like this:

```dpp
using system.windows.msdos;

fn::load -> created(Main): protected {
    kernel::loaddistrubution: krnl.load;
    end::line* protected
}
```

This demonstrates:

- namespace imports  
- a protected function  
- a kernel directive  
- the D++ termination marker  

---

## Running a D++ Program

Once the toolchain is installed, running a D++ file follows a simple pattern:

```
dpp run main.dpp
```

The runtime will:

1. Resolve namespaces  
2. Validate protected blocks  
3. Bind kernel directives  
4. Execute the program  

---

## Basic Concepts to Know Early

### Namespaces  
D++ uses deep, structured namespaces to reflect system hierarchy.

### Protected Execution  
Functions marked with `: protected` run under controlled runtime conditions.

### Kernel Directives  
Calls like `kernel::loaddistrubution` interact with system‑level components.

### Termination Marker  
`end::line* protected` signals the end of a protected block.

---

This section prepares you for writing real D++ code and understanding how the language behaves during execution.
