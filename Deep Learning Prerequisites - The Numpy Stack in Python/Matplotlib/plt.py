# https://stackoverflow.com/questions/23061657/plot-histogram-with-colors-taken-from-colormap
import numpy as n
import matplotlib.pyplot as plt

# Random gaussian data.
Ntotal = 1000
data = 0.05 * n.random.randn(Ntotal) + 0.5

# This is  the colormap I'd like to use.
cm = plt.cm.get_cmap('RdYlBu_r')

# Plot histogram.
n, bins, patches = plt.hist(data, 25, normed=1, color='green')
bin_centers = 0.5 * (bins[:-1] + bins[1:])

# scale values to interval [0,1]
col = bin_centers - min(bin_centers)
col /= max(col)

for c, p in zip(col, patches):
    plt.setp(p, 'facecolor', cm(c))

plt.show()