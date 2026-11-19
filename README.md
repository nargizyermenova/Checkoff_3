# Run-Length Encoding in C
For my COMP 211 Checkoff 3, I explored where run-length encoding (RLE) is useful. RLE is a lossless compression method that stores consecutive copies of a value as a '(count, value)' pair. For example, '08 00' represents eight black pixels in my demo.

## What I explored
I compared two ways of reading the same 8x8 image of alternating black and white rows. Each pixel uses one byte, so the starting size is 64 bytes.

| Reading order | Runs | Encoded size |
| --- | ---:| ---: |
| Across rows | 8 | 16 bytes |
| Down columns | 64 | 128 bytes |

Reading across groups eight identical pixels into each run. Reading down makes the color change at every step, so every pixel needs its own two-byte pair. What surprised me was that changing how I index the same C array could make the encoded data either one-quarter or twice its original size.

## Run the demo
With a C compiler installed, run these commands from the repository folder:
1) cc -std=c99 -Wall -Wextra rle_demo.c -o rle_demo
2) ./rle_demo

## Slides and resources
1) [View presentation slides, PDF] https://github.com/nargizyermenova/Checkoff_3/blob/89c051d40c00e0aaa6e762d0bcbd445d16b996cd/Run-length%20encoding.pdf
2) [AI exploration conversation] https://chatgpt.com/share/6afefaa4-c7e4-83ea-80a6-cf61c564f299
