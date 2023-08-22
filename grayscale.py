import cv2

img = cv2.imread('roopy.jpg', cv2.IMREAD_GRAYSCALE)

img2 = cv2.imread('roopy.jpg')
img2_gray = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)

img3 = cv2.imread('roopy.jpg')
img3_gray = (0.299 * img3[:, :, 2]) + (0.587 * img3[:, :, 1]) + (0.114 * img3[:, :, 0])

cv2.imwrite('roopy_img3_gray.jpg', img3_gray)
img3 = cv2.imread('roopy_img3_gray.jpg')


cv2.imshow("img", img)
cv2.imshow("img2", img2_gray)
cv2.imshow("img3", img3)


cv2.waitKey(0)
cv2.destroyWindow()
