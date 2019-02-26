import pyhdfeos
import numpy as np

data = pyhdfeos.readgrid(28*72)
print(data.shape, data.dtype)
print(data)
print(data.max())
