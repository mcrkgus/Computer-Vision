import numpy as np
import cv2

# 마우스 이벤트 속성 활용하기
'''
• event: 마우스 이벤트 종류. cv2.EVENT_로 시작하는 상수.
• x: 마우스 이벤트가 발생한 x 좌표
• y: 마우스 이벤트가 발생한 y 좌표
• flags: 마우스 이벤트 발생 시 상태. cv2.EVENT_FLAG_로 시작하는 상수
• param: cv2.setMouseCallback() 함수에서 설정한 데이터
'''
def MouseClick(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN:
        print("왼쪽 마우스 클릭(DOWN)함", event, x, y, param)
    elif event == cv2.EVENT_RBUTTONDOWN:
        print("오른쪽 마우스 클릭함", event, x, y, param)
    elif event == cv2.EVENT_LBUTTONUP:
        print("왼쪽 마우스 클릭 후 뗀 것(UP)", event, x, y, param)
    elif event == 7:  # 왼쪽 더블 클릭 인자값 : 7, 인자값으로도 설정 가능
        print("왼쪽 마우스 더블 클릭", event, x, y, param)

# 배열로 이미지 생성
image = np.full( (500,500), 0, np.uint8)  # 크기, 색상, 데이터 타입

cv2.imshow('test', image)

# 마우스 이벤트 연동, 마우스 콜백 함수: setMouseCallback
cv2.setMouseCallback('test', MouseClick)
cv2.waitKey(0)
cv2.destroyAllWindows()
