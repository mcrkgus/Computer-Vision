import cv2
import numpy as np

img = cv2.imread("roopy.bmp", cv2.IMREAD_GRAYSCALE)

#라플라시안 필터 적용해서 에지 검출
laplacian_img = cv2.Laplacian(img, cv2.CV_8U, ksize=5)

# 결과 출력
cv2.imshow('Original', img)
cv2.imshow('Laplacian', laplacian_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
