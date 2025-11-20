<div align="center">

# StackSmash

![C](https://img.shields.io/badge/Language-C-blue?style=flat&logo=c)
![Python](https://img.shields.io/badge/Language-Python-yellow?style=flat&logo=python)
![Type](https://img.shields.io/badge/Type-Binary_Exploitation-red)

<p>
  <strong>A Buffer Overflow laboratory demonstrating memory corruption attacks.</strong>
</p>

[Report Bug](https://github.com/egetones/stacksmash/issues)

</div>

---

## Description

**StackSmash** is an educational project focusing on **Binary Exploitation**. It consists of two parts:
1.  **The Victim:** A vulnerable C TCP server intentionally coded with a buffer overflow flaw (`strcpy` without bounds checking).
2.  **The Attacker:** A Python exploit script designed to overflow the stack memory, overwrite the Instruction Pointer (EIP/RIP), and crash the application (DoS).

This project demonstrates how memory management errors in low-level languages can lead to critical security vulnerabilities.

### The Vulnerability

The server allocates a **64-byte** buffer.
```c
char buffer[64];
strcpy(buffer, input); // No size check!
```
If we send **200 bytes**, the extra data spills over into adjacent memory, overwriting the return address and causing a **Segmentation Fault**.

---

## Usage

### 1. Compile the Victim (Disable Protections)
We compile with security mitigations disabled (ASLR/Canary) to study the core concept.
```bash
make
```

### 2. Run the Server
Open a terminal and start the vulnerable server:
```bash
./vuln_server
```
*It will listen on port 9999.*

### 3. Run the Exploit
Open a second terminal and fire the payload:
```bash
python3 exploit.py 127.0.0.1 9999
```

### 4. Observe the Crash
Check the first terminal. You should see a `Segmentation fault (core dumped)` error. The server has been successfully smashed.

---

## ⚠️ Disclaimer

This project involves **deliberately vulnerable code**. Do not run this on a public network or expose the port to the internet. It is strictly for educational purposes in a controlled local environment.

---

## License

Distributed under the MIT License. See `LICENSE` for more information.
