TCP(Transmission Control Protocol)
----------------------------------

-	Layer 4 계층 프로토콜이다.<br><br>
-	TCP는연결 지향 서비스(Connection-Oriented Service)가 제공되므로 데이터에 대한 무결성이 보장되며 양방향 데이터 전송이 가능한 전이중 서비스(Full Duplex Service)를 제공한다.<br><br>
-	스트림 데이터 서비스(Strem Data Service)가 제공되기 때문에 상위 계층으로부터 수신한 데이터 스트림을 세그먼트(Segment)형식의 단위로 분리하여 네트워크로 전송하며 목적지에서는 TCP에 의해서 세그먼트를 재조립한다.<br><br>
-	만약 전송된 세그먼트에 대한 응답을 정해진 타이머 안에 수신하지 못하면 해당 세그먼트를 재전송함으로 신뢰적인 서비스(Reliability Service)를 제공한다.<br><br>

TCP & UDP
---------

![image](https://user-images.githubusercontent.com/56240505/72355380-b13de880-372a-11ea-8b22-b78251a42a35.png)<br><br>

-	TCP/IP 프로토콜은 이기종 시스템간의 통신을 위한 표준 프로토콜로, 프로토콜의 집합이다.<br><br>
-	TCP와 UDP 모두 TCP/IP 프로토콜에 속하며, OSI 7계층의 전송 계층에 해당하는 프로토콜이다.<br><br>
-	두 프로토콜은 전송 방식이 다르며, 장단점이 있다.<br><br>

Connection-Oriented Service
---------------------------

![image](https://user-images.githubusercontent.com/56240505/77321322-60afc080-6d55-11ea-8956-8252cdb2ea2a.png)<br><br>

-	TCP는 통신 시 서로의 신뢰 관계를 맽은 후 통신을 하기 때문에 데이터의 무결성을 보장받을 수 있다.<br><br>
-	3-way Handshaking 과정<br>
	-	1. Client는 Server에게 통신 요청을 개시하는 SYN와 첫번째 세그먼트를 알리는 Seq(100)을 전송한다.<br>
	-	2. SYN을 수신한 Server는 이에 대한 응답으로 Client에게 Ack(101)와 Seq(200)을 전송하며, 자기 자신도 Client에게 통신 요청을 개시하는 SYN을 함께 전송한다.<br>
	-	3. SYN을 수신한 Client는 이에 대한 응답으로 Server에게 Ack(201)를 전송함으로써 통신 연결이 성립되게 된다.<br><br>

Full Duplex Service
-------------------

![image](https://user-images.githubusercontent.com/56240505/77322374-fbf56580-6d56-11ea-9ff9-b6d0d63af141.png)<br><br>

-	정보의 송신과 수신을 동시에 행하는 것이 가능하다.<br><br>

-	반이중 서비스는 정보가 송신 및 수신될 때 동시에 수신 및 송신이 이루어지지 않는다.<br><br>

Strem Data Service
------------------

![image](https://user-images.githubusercontent.com/56240505/77322595-4ecf1d00-6d57-11ea-8feb-d92549b1f255.png)<br><br>

-	데이터를 세그먼트 형식의 단위로 분리하여 전송한다.<br><br>

Reliability Service
-------------------

![image](https://user-images.githubusercontent.com/56240505/77322785-99e93000-6d57-11ea-80fa-2789080092a5.png)<br><br>

-	TCP는 세그먼트에 포함된 체크섬을 이용하여 세그먼트 손상 여부를 검사한다.<br><br>
-	만약 세그먼트 손상이 발견 된다면 수신측에서는 해당 세그먼트를 폐기하고 송신측으로 응답을 보내지 않는다.<br><br>
-	또한 송신측은 일정 시간이 초과되기 이전에 응답을 수신하지 못하면 해당 세그먼트가 손상되었거나 손실되었다고 간주한다.<br><br>
-	이런 경우 송신측에서는 전송되는 각 세그먼트마다 시간 초과 카운트를 이용하여 주기적으로 확인하다가 카운터값이 만기되면 해당 세그먼트를 재전송한다.<br><br>

Flow Control
------------

![image](https://user-images.githubusercontent.com/56240505/77323390-84c0d100-6d58-11ea-8033-a98a528ebb40.png)<br><br>

-	통신에 참여한 두 호스트가 송수신할 수 있는 데이터 양을 네트워크 상황에 맞게 조절하는 기능을 제공한다.<br><br>
-	Stol-and wait : 일반적으로 데이터를 전송하기 이전에 송신한 데이터에 대한 응답을 먼저 수신해야지만 그 다음 데이터를 전송할 수 있다.<br><br>
-	TCP는 슬라이딩 윈도우(Sliding Window) 기능을 이용하여 상호 협의한 윈도우 크기만큼 데이터를 송신하고 이에 대한 응답만 수신하면 그 다음 윈도우 크기만큼 데이터를 전송한다.<br><br>

Congestion Control
------------------

-	과도한 패킷이 들어와 라우터의 버퍼 용량을 초과하게 될 때 혼잡이 발생하며 패킷들이 손실되게 된다.<br><br>
-	이러한 문제를 해결하기 위해서 혼잡 제어 기능을 이용하여 송신측에서 패킷을 보내는 전송율을 제어한다.<br><br>

TCP Header
----------

![image](https://user-images.githubusercontent.com/56240505/77376203-1d843a80-6db3-11ea-9536-96eedeaf650a.png)<br><br> ![image](https://user-images.githubusercontent.com/56240505/77376223-31c83780-6db3-11ea-935f-895cbc4c37fc.png)<br><br>

-	TCP 헤더는 20byte이며 헤더 안에는 3-way Handshaking, 순서화 기능, 동기화 기능, 재전송 기능, 흐름 제어, 오류 제어, 오류 정정, 혼잡 제어를 하기 위한 필드 값과 포트번호가 포함되어 있다.<br><br>

-	①, ② : 출발지, 목적지에서 수행되는 프로세스가 사용하는 포트 번호이다.<br><br>

-	③ : 순서 번호는 자신이 전송하는 데이터의 각 Byte마다 고유한 번호를 부여하며 데이터 스트림 순서, 중복 된 세그먼트에 대한 구분, 데이터 수신 확인을 담당한다.<br><br>

-	④ : 확인 번호는 수신측에서 송신측으로 부터 받은 세그먼트에 대한 응답을 사용할 때 사용한다.<br><br>

-	⑤ : 32bit 워드 단위로서 헤더의 길이를 지정하며 옵션 필드가 가변 길이이기 때문에 필요하다.<br><br>

-	⑥ : 차후에 사용을 위해 예약된 6bit 필드 값이다.<br><br>

-	⑦ : TCP 패킷 종류를 나타내기 위한 필드이며 총 6개의 값으로 구성된다.<br><br>

-	⑧ : 수신측 입장에서 현재 데이터를 수신할 수 있는 버퍼 크기를 알려주며 혼잡 제어를 담당한다.<br><br>

-	⑨ : TCP/IP 프로토콜을 사용하는 대부분의 데이터에 대한 오류 검사 또는 보호를 담당한다.<br><br>

-	⑩ : URG 플래그가 설정된 경우만 사용되며 수신측에게 긴급한 데이터를 전송할 때 사용된다.<br><br>

-	⑪ : 목적지에게 부가 정보를 전달하거나 다른 옵션 정렬을 맞추기 위해서 사용한다.<br><br>

TCP 프로토콜을 사용하는 어플리케이션 프로토콜
---------------------------------------------

-	HTTP(Port 80)
-	TELNET(Port 23)
-	SSH(Port 22)
-	FTP(Port 20/21)
-	SMTP(Port 25)
-	POP(Port 110)<br><br>

---

Reference
---------

-	[TCP?](https://m.blog.naver.com/hatesunny/220790242308)
-	[TCP 헤더](https://m.blog.naver.com/hatesunny/220790300052)
