import cv2
import matplotlib.pyplot as plt

image = cv2.imread('dogs.jpg')

# 1) 이미지 회전 cv2.rotate(ndarray, rotatecode), np.rot90()
# 오른쪽으로 90도 회전
img_r_90 = cv2.rotate(image, cv2.ROTATE_90_CLOCKWISE)
plt.imshow(img_r_90)

# 180도 회전
img_r_180 = cv2.rotate(image, cv2.ROTATE_180)
plt.imshow(img_r_180)

# 2) 상하 좌우 반전 cv2.flip(ndarray, flipcode), np.flip()
# flipcode = 0 : 상하 반전
img_flip_up = cv2.flip(image, 0)
plt.imshow(img_flip_up)

# flipcode > 0 : 좌우 반전
img_flip_lr = cv2.flip(image, 1)
plt.imshow(img_flip_lr)

# flipcode < 0 :상하좌우 반전
img_flip_up_lr = cv2.flip(image, -1)
plt.imshow(img_flip_up_lr)

plt.show()
