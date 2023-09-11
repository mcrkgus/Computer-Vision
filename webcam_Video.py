#OpenCV를 사용하여 웹캠으로부터 비디오를 캡처하고 저장하는 예제
import cv2

# 캠 로드
cam = cv2.VideoCapture(0)

# 캠의 속성값 로드
width = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = cam.get(cv2.CAP_PROP_FPS)

fourcc = cv2.VideoWriter_fourcc(*'XVID')  # ('X','V','I','D') , 저장 코덱
video = cv2.VideoWriter( 'res.mp4', fourcc, fps, (width, height) )  # 저장 파일명, 코덱, fps, 크기 지정 

while(cam.isOpened()):
    # ret, frame 리턴
    ret, frame = cam.read()

    if ret:
        cv2.imshow("Video Cam", frame)  # cam 보여주기
        video.write(frame)  # 프레임 저장
        if cv2.waitKey(1) == ord('q'):  # q 입력시 종료
            break

# 종료
cam.release()
video.release()
cv2.destroyAllWindows()
