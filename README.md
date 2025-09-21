# File Compressor in C (RLE)

A **file compression and decompression tool** written in C using **Run-Length Encoding (RLE)**.  
This project demonstrates how to handle **file I/O**, implement a simple **compression algorithm**, and create a command-line utility.

---

## Overview
This tool supports two operations:

- **Compression** – Reads an input file, compresses its contents using RLE, and writes to an output file.
- **Decompression** – Reads a compressed file and restores the original file.

RLE replaces consecutive repeated characters with a **count + character** pair.  

Example:
```
Input:  aaabbcdddd
Compressed:  3a2b1c4d
Decompressed: aaabbcdddd
```
## Project Structure

```
file-compressor/
├─ src/
│  ├─ main.c          # CLI interface
│  └─ compressor.c    # RLE compression/decompression logic
├─ include/
│  └─ compressor.h    # function declarations
├─ Makefile           # build instructions
└─ README.md
```

---


## Learning Goals
	•	Understand file I/O in C (fopen, fread, fwrite)
	•	Implement a basic compression algorithm
	•	Learn about buffers, loops & memory efficiency

---

## Tech Used
	•	Language: C (C99)
	•	Platform: Linux / macOS (POSIX)
