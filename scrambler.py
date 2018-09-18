from PIL import Image

import numpy as np
import sys
import random
path = sys.argv[1]
print(path)
im_frame = Image.open(path)
width = im_frame.size[0]
height = im_frame.size[1]
np_frame = np.array(im_frame.getdata())
img = np_frame.reshape((im_frame.size[0], im_frame.size[1], np_frame.shape[1]))


indices = list(range(np_frame.shape[0]))
random.shuffle(indices)
scrambled = np.array(indices)

with open("out.data", "w+") as f:
    f.write(str(width) + "\n")
    f.write(str(height) + "\n")

    for i in scrambled:
        x = i % width
        y = int((i - x) / width)
        f.write("{}, {}, {}, {}, {}\n".format(x, y, img[x][y][0], img[x][y][1], img[x][y][2]))

