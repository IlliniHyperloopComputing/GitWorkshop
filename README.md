# GitWorkshop

Let's do a little problem to learn Git and a little bit of C++

In this problem, you are provided an input file "input.data" describing a scrambled image. It is in this form:

[width]\n
[height]\n
[x] [y] [r] [g] [b] 
[x] [y] [r] [g] [b] 
[x] [y] [r] [g] [b] 
...

\n is the newline character
width is the width of the image
height is the height of the image
Each row after width and height describes a single pixel
In each row, [x][y] represents the pixel at position (x, y). [r] [g] and [b] represent 3 Red, Green, and Blue values making up that pixel.

Your task is to take this input, descramble it, and spit it out in [pbm format](https://en.wikipedia.org/wiki/Netpbm_format).

It will look something like: 

```
P3 #identifier
3 2 #width and height
255 #max value for each rgb
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0
```

Each triplet represents a single pixel, arranged how they appear in the image.

I've given a skeleton that handles reading and writing from the files. 
It also gives the width and the height, and writes the header for the pbm format. All you have to worry about are the pixel values.

Take some time to understand the code as things are, then write your solution. After that, make a pull request from your feature branch to check it in!

Run `make` to build and `./workshop` to run your code. Good luck!

**Helpful Links**

[Parsing strings in c++](https://stackoverflow.com/questions/17724925/parse-string-containing-numbers-into-integer-array)

[2D Vectors in c++](https://stackoverflow.com/questions/9694838/how-to-implement-2d-vector-array)

**Extra credit:**

If you want to mess around, feel free to use scrambler.py to scramble your own images. Just run 
```
python3 scrambler.py [image path]
``` 
and it will write your scrambled image in the above format to out.data
