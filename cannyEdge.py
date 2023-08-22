import cv2

#cv2.Canny(image, threshold1, threshold2, edges=None, apertureSize=None, L2gradient=None) -> edges

my_img = cv2.imread('building.jpg', cv2.IMREAD_GRAYSCALE)

if my_img is None:
    print('IMAGE LOAD FAILED')
    sys.exit()

dst = cv2.Canny(my_img, 50, 150) # 하단 임계값과 상단 임계값은 실험적으로 결정하기

cv2.imshow('my_img', my_img)
cv2.imshow('dst', dst)
cv2.waitKey()

cv2.destroyAllWindows()
