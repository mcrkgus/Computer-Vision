import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('roopy.jpg', cv2.IMREAD_GRAYSCALE)

kernel = np.ones((5, 5), np.uint8)
erosion = cv2.erode(img, kernel, iterations=1)
dilates = cv2.dilate(img, kernel, iterations=1)
ret, img_th = cv2.threshold(img, 110, 255, cv2.THRESH_BINARY)
img_res = cv2.morphologyEx(img_th, cv2.MORPH_CLOSE, kernel)

plt.subplot(141),plt.imshow(img),plt.title('original')
plt.subplot(142),plt.imshow(erosion),plt.title('erosion')
plt.subplot(143),plt.imshow(dilates),plt.title('dilate')
plt.subplot(144),plt.imshow(img_res),plt.title('img_res')

plt.show()
