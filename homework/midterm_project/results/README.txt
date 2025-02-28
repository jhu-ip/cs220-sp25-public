Sample images generated as follows:

$ ./project data/kitten.ppm results/kitten-invert.ppm invert
original image : cols = 770, rows = 400 [data/kitten.ppm]
modified image : cols = 770, rows = 400 [results/kitten-invert.ppm]

$ ./project data/kitten.ppm results/kitten-zo.ppm zoom-out
original image : cols = 770, rows = 400 [data/kitten.ppm]
modified image : cols = 385, rows = 200 [results/kitten-zo.ppm]

$ ./project data/kitten.ppm results/kitten-bin.ppm binarize 150
original image : cols = 770, rows = 400 [data/kitten.ppm]
modified image : cols = 770, rows = 400 [results/kitten-bin.ppm]

$ ./project data/kitten.ppm results/kitten-point.ppm pointilism
original image : cols = 770, rows = 400 [data/kitten.ppm]
modified image : cols = 770, rows = 400 [results/kitten-point.ppm]

$ ./project data/kitten.ppm results/kitten-blur.ppm blur 1
original image : cols = 770, rows = 400 [data/kitten.ppm]
modified image : cols = 770, rows = 400 [results/kitten-blur.ppm]

$ ./project data/kitten.ppm results/kitten-blur2.ppm blur 2.8
original image : cols = 770, rows = 400 [data/kitten.ppm]
modified image : cols = 770, rows = 400 [results/kitten-blur2.ppm]

$ ./project data/kitten.ppm results/kitten-crop.ppm crop 20 20 250 250
original image : cols = 770, rows = 400 [data/kitten.ppm]
modified image : cols = 230, rows = 230 [results/kitten-crop.ppm]
