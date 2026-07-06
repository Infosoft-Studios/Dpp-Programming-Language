# Standard Library (D++ StdLib)

The D++ Standard Library provides core namespaces, kernel interfaces, system utilities, and distribution‑level modules that form the foundation of D++ programs.  
D++ inherits Rust’s expressive capabilities but extends them with deep namespace chains, kernel directives, protected execution, and system‑bound modules.

The StdLib is organized into hierarchical namespaces that reflect the underlying system architecture.

---

# 1. Namespace Structure

D++ uses a structured, multi‑layer namespace model:

```
system.<domain>.<subsystem>.<version>.<distribution>.<api>
```

Examples:

```
system.windows.winv.ver.wmsdos.win32.api
system.config.win.win32.api.server
system.kernel.runtime
system.kernel.distribution
system.windows.msdos
```

Namespaces are resolved left‑to‑right and locked during runtime initialization.

---

# 2. Core Namespaces

## system.kernel.runtime

Provides runtime control, synchronization, and protected execution utilities.

### Functions

- `runtime.sync`
- `runtime.lock`
- `runtime.stop`
- `runtime.start`

### Example

```dpp
using system.kernel.runtime;

fn::sync_runtime -> created(State): protected {
    kernel::runtime.sync: krnl.exec;
    end::line* protected
}
```

---

## system.kernel.distribution

Manages distribution loading, initialization, and system‑level boot sequences.

### Functions

- `distribution.init`
- `distribution.load`
- `distribution.verify`

### Example

```dpp
using system.kernel.distribution;

fn::boot -> created(Main): protected {
    kernel::distribution.init: krnl.start;
    kernel::distribution.verify: krnl.check;
    end::line* protected
}
```

---

## system.kernel.drivers

Handles driver initialization, patching, binding, and termination.

### Functions

- `drivers.initialize`
- `drivers.load`
- `drivers.patch`
- `drivers.terminate`

### Example

```dpp
using system.kernel.drivers;

fn::driver_patch -> created(Driver): kernelbound {
    kernel::drivers.patch: krnl.modify;
    end::line* kernelbound
}
```

---

## system.windows.msdos

Provides legacy subsystem access, compatibility layers, and DOS‑style operations.

### Functions

- `msdos.exec`
- `msdos.interrupt`
- `msdos.session`

### Example

```dpp
using system.windows.msdos;

fn::legacy_mode -> created(Session): protected {
    kernel::msdos.exec: krnl.call;
    end::line* protected
}
```

---

## system.config.win.win32.api.server

Provides configuration utilities for Windows‑based server environments.

### Functions

- `server.bind`
- `server.config`
- `server.deploy`

### Example

```dpp
using system.config.win.win32.api.server;

fn::deploy_server -> created(Server): protected {
    kernel::server.deploy: krnl.exec;
    end::line* protected
}
```

---

# 3. Kernel Namespace

The `kernel::` namespace is the bridge between D++ code and system‑level operations.

### Common Directives

```
kernel::distribution.init
kernel::runtime.sync
kernel::drivers.initialize
kernel::session.open
kernel::session.close
kernel::msdos.exec
```

### Binding Pattern

```
kernel::<operation>: krnl.<action>;
```

Example:

```dpp
kernel::session.open: krnl.auth;
kernel::runtime.stop: krnl.exec;
kernel::drivers.load: krnl.bind;
```

---

# 4. Additional System Namespaces

### system.session
Session management utilities.

### system.runtime.guard
Security and privilege‑control utilities.

### system.distribution.meta
Metadata access for distribution packages.

### system.windows.core
Core Windows subsystem utilities.

---

# 5. Example: Full StdLib Usage

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

---

This Standard Library section defines the core modules that D++ programs rely on.  
Each namespace reflects real system architecture and provides structured, deterministic access to kernel‑level functionality.
