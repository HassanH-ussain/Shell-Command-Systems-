Assignment 3

How to Use

1. Compile the program using a C++ compiler.
2. Run the compiled executable.

Overview

- **PAGE_SIZE**: Size of each page in bytes.
- **FRAME_SIZE**: Size of each frame in bytes.
- **NUM_PAGES**: Number of pages in logical memory.
- **NUM_FRAMES**: Number of frames in physical memory.

Implementation Details

1. Random logical addresses are generated within the range of logical memory.
2. Page/frame table is initialized with a circular mapping of pages to frames.
3. Physical memory is allocated and initialized.
4. Logical addresses are translated into physical addresses using the page/frame table.
5. The translation results (logical address, physical address, page number, and offset) are printed.

Run the code and randomly generated logical addresses will be converted to physical addresses and have their page number, offset, and address printed out
