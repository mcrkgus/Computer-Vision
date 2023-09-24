#이미지 처리와 변환 작업을 수행하며, 결과 이미지를 Matplotlib를 사용하여 시각화하는 예제


import cv2
import matplotlib.pyplot as plt
import numpy as np

# 보간법(Interpolation) : 사이즈가 변할 때 픽셀 사이의 값을 조절하는 방법을 의미
img = cv2.imread('dogs.jpg')
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
# plt.show()

# 1) cv2.resize( image, dsize, fx, fy, interpolation ) : 이미지 크기 조절
# 크기를 2배로 변경
img_re = cv2.resize(img, None, fx=2.0, fy=2.0, interpolation=cv2.INTER_CUBIC)
plt.imshow(cv2.cvtColor(img_re, cv2.COLOR_BGR2RGB))
# plt.show()

# 2) cv2.warpAffine( image, M, dsize ) : 이미지의 위치 변경
h, w = img.shape[:2]
M = np.float32([[1, 0, 50], [0, 1, 10]])
dst = cv2.warpAffine(img, M, (w, h))

plt.imshow(cv2.cvtColor(dst, cv2.COLOR_BGR2RGB))
# plt.show()

# 3) cv2.getRotationMatrix2D( center, angle, scale ) : 이미지 회전
h, w = img.shape[:2]
M = cv2.getRotationMatrix2D( (w/2, h/2), 90, 0.5 )  # ( 회전 중심, 각도, 크기 )
print(M)
dst = cv2.warpAffine(img, M, (w,h))

plt.imshow(cv2.cvtColor(dst, cv2.COLOR_BGR2RGB))
plt.show()
