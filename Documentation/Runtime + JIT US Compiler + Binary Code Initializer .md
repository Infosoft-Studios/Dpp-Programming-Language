# 9. Runtime + JIT US Compiler + Binary Code Initializer

This section describes the D++ Runtime Execution Model, the JIT US (Unified Stream) Compiler, and the Binary Code Initializer responsible for preparing executable units during program startup.

---

## 9.1 Runtime Overview

The D++ Runtime is a lightweight execution engine designed to:

- Load compiled bytecode segments
- Initialize binary instruction blocks
- Execute instructions in a deterministic order
- Provide JIT compilation for hot paths
- Manage memory, stack frames, and symbol tables

The runtime operates in two phases:

1. **Initialization Phase**  
   Loads binary segments, resolves symbols, prepares execution frames.

2. **Execution Phase**  
   Runs bytecode or JIT‑compiled native instructions.

---

## 9.2 Runtime Architecture

```
+---------------------------+
| D++ Program (.dpp)        |
+---------------------------+
            |
            v
+---------------------------+
| D++ Compiler Frontend     |
| (AST → IR → Bytecode)     |
+---------------------------+
            |
            v
+---------------------------+
| Runtime Loader            |
| (Binary Code Initializer) |
+---------------------------+
            |
            v
+---------------------------+
| JIT US Compiler           |
| (Hot Path Native Gen)     |
+---------------------------+
            |
            v
+---------------------------+
| Runtime VM                |
| (Bytecode Executor)       |
+---------------------------+
```

---

## 9.3 Binary Code Initializer

The Binary Code Initializer (BCI) is responsible for:

- Reading compiled `.dppbin` binary segments
- Validating headers and instruction tables
- Allocating memory regions for execution
- Mapping bytecode into runtime blocks
- Preparing JIT‑eligible segments

### BCI Header Format

```
struct BCIHeader {
    u32 magic;        // 0xDPP9
    u32 version;      // Runtime version
    u32 instr_count;  // Number of bytecode instructions
    u32 flags;        // Execution flags
};
```

### BCI Initialization Steps

1. Read header  
2. Validate magic number  
3. Allocate instruction buffer  
4. Load bytecode  
5. Register segment with runtime  
6. Mark hot‑path candidates

---

## 9.4 Bytecode Instruction Format

Each instruction is encoded as:

```
[ OPCODE | ARG0 | ARG1 | ARG2 ]
```

Example:

```
LOAD   x
LOAD   y
ADD
PRINT
```

Binary representation:

```
0x01 0x10
0x01 0x11
0x02
0x03
```

---

## 9.5 JIT US Compiler

The JIT US Compiler activates when:

- A function or loop is executed repeatedly
- A bytecode block exceeds the hot‑path threshold
- The runtime detects predictable execution patterns

### JIT Compilation Steps

1. Identify hot path  
2. Convert bytecode → IR  
3. Optimize IR  
4. Generate native machine code  
5. Patch runtime to call native block  
6. Cache compiled block

### Example JIT Flow

```
Bytecode → IR → Native → Patch → Execute
```

### JIT Optimization Techniques

- Constant folding  
- Dead instruction elimination  
- Register allocation  
- Loop unrolling  
- Branch prediction hints  

---

## 9.6 Runtime Execution Model

The runtime uses a **stack‑based VM**:

### Stack Operations

```
PUSH value
POP
LOAD var
STORE var
CALL func
RET
```

### Execution Loop

```
while (pc < instr_count) {
    opcode = instr[pc];
    switch(opcode) {
        case LOAD:   stack.push(vars[arg0]); break;
        case STORE:  vars[arg0] = stack.pop(); break;
        case ADD:    stack.push(stack.pop() + stack.pop()); break;
        case PRINT:  print(stack.pop()); break;
        case CALL:   call_function(arg0); break;
        case RET:    return; break;
    }
    pc++;
}
```

---

## 9.7 Native Execution (JIT)

When JIT is active:

```
bytecode_block → native_block
runtime.replace(bytecode_block, native_block)
execute(native_block)
```

Native blocks are stored in:

```
/runtime/cache/native/
```

---

## 9.8 Binary Code Initializer + JIT Integration

The BCI marks segments with:

```
FLAG_JIT_ELIGIBLE
FLAG_HOT_PATH
FLAG_NATIVE_PATCHED
```

The JIT compiler reads these flags to determine:

- Which blocks to compile
- Which blocks to skip
- Which blocks to patch

---

## 9.9 Example: Full Runtime Flow

```
1. Program starts
2. Compiler generates bytecode
3. BCI loads binary segments
4. Runtime executes bytecode
5. Hot path detected
6. JIT compiles native block
7. Runtime patches execution
8. Native block runs
9. Program completes
```

---

## 9.10 Summary

The Runtime + JIT US Compiler + Binary Code Initializer form the core of D++ execution:

- **BCI** loads and prepares binary code  
- **Runtime VM** executes bytecode deterministically  
- **JIT US Compiler** accelerates hot paths with native code  

This architecture provides both portability and performance.
