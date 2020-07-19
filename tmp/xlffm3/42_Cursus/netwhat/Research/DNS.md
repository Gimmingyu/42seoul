DNS(Domain Name Service)
------------------------

-	DNS란 도메인을 IP로 변환하거나, IP를 도메인으로 다시 변경해주는 것을 말한다.<br><br>
-	인터넷은 서버들을 유일하게 구분할 수 있는 IP 주소를 기본 체계로 이용하는데, 숫자로 이루어진 조합이라 인간이 기억하기에 무리가 있다.<br><br>
-	따라서 DNS를 이용해 IP 주소를 인간이 기억하기 편한 언어 체계로 변환하는 작업이 필요하다.<br><br>
-	DNS 메시지를 전달하기 위해 하위 트랜스포트 계층의 프로토콜을 이용하므로 어플리케이션 계층 프로토콜이다.<br><br>

DNS 역할 및 특징
----------------

-	1. 호스트 별칭
	-	복잡한 호스트 네임을 가진 호스트는 하나 이상의 벼며을 가질 수 있다.<br><br>
-	2. 메일 서버 별칭<br><br>
-	3. 부하 분산
	-	같은 도메인에 대해서 여러 IP 지정이 가능하며, 같은 도메인에 대해 사용자가 질의할 경우 DNS 서버는 IP를 번갈아가며 알려준다.<br><br>
-	HTTP , FTP , SMTP 등과 달리 사용자가 직접 요청하는 프로토콜이 아니다.<br><br>
-	사용자가 브라우저에서 naver.com을 검색하는 경우, 브라우저가 DNS서버에게 naver.com를 IP로 변경해달라고 요청한다.<br><br>

Port
----

-	UPD/53을 주로 사용한다.<br><br>
-	TCP/53은 전송 데이터가 512Byte 이상일 때거나, Zone Transfer의 경우에만 사용한다.<br><br>

도메인 이름의 체계
------------------

![image](https://user-images.githubusercontent.com/56240505/77394698-589e6200-6de3-11ea-8d2c-7bd996a3dd95.png)<br><br>

-	인터넷 도메인은 하나의 역트리 구조를 하고 있다.<br><br>
-	인터넷 도메인의 체계에서 최상위는 루트로서 인터넷 도메인의 시작점이 된다.<br><br>
-	그리고 이 루트 도메인 바로 아래단계에 있는 것을 1단계 도메인이라고 하며 이를 최상위 도메인이라고 한다.<br><br>
-	이를 약어로 TLD(Top Level Domain)이라고 하며, TLD는 국가명을 나타내는 국가 TLD와 일반적으로 사용되는 일반 TLD로 구분된다.<br><br>
-	도메인을 구입할 경우 1단계의 도메인중에 하나를 선택하고 원하는 도메인명을 지정하여 등록한다.<br><br>

도메인 질의 과정
----------------

![image](https://user-images.githubusercontent.com/56240505/77394999-fabe4a00-6de3-11ea-927d-2a3185589eb3.png)<br><br>

-	1. DNS Client(웹 브라우저 등)는 로컬 DNS에게 www.naver.com을 질의한다.<br><br>
-	2. 로컬 DNS가 Root DNS에게 www.naver.com을 묻는다.<br><br>
-	3. Root DNS가 com을 인식하고 com을 관리하는 최상위 도메인 DNS 서버의 IP를 로컬 DNS에게 알려준다.<br><br>
-	4. 다시 로컬 DNS가 com도메인을 관리하는 최상위 도메인 DNS서버에게 www.naver.com을 질의한다.<br><br>
-	5. 최상위 도메인 DNS서버가 naver.com을 인식하고 naver.com을 관리하는 책임DNS 서버의 IP를 로컬 DNS에게 알려준다.<br><br>
-	6. 로컬 DNS는 책임 DNS서버에게 www.naver.com을 질의한다.<br><br>
-	7. 책임 DNS서버에서 www.naver.com 호스트에 대한 IP를 알려준다.<br><br>
-	8. 로컬 DNS가 DNS Client에게 www.naver.com의 IP를 알려준다.<br><br>
-	DNS 서버는 한 번 검색한 결과는 메모리의 캐시에 기록하며, 같은 정보가 요청되면 캐시에 있는 정보를 전송한다.<br><br>
-	이때, 캐시에는 유효기간(TTL:Time To Live)이 정해져 있으므로 유효기간이 지난 정보는 캐시에서 삭제된다.<br><br>

---

Reference
---------

-	[DNS[Domain Name Service]](https://run-it.tistory.com/32?category=668092)
-	[DNS서버(네임서버)의 이해](https://webdir.tistory.com/161)
-	[Network - Application 계층) DNS 프로토콜](https://galid1.tistory.com/53)
