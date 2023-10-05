src = cv2.imread('roopy.jpg', cv2.IMREAD_GRAYSCALE)

if src is None:
    print('Image load failed!')
    sys.exit()

# dx와 dy를 합쳐서 출력
# delta 값을 지정해주지 않으면 미분이 - 부분은 0이 됨
dx = cv2.Sobel(src, -1, 1, 0, delta=128)
dy = cv2.Sobel(src, -1, 0, 1, delta=128)

cv2.imshow('src', src)
cv2.imshow('dx', dx)
cv2.imshow('dy', dy)
cv2.waitKey(0)
cv2.destroyAllWindows()


