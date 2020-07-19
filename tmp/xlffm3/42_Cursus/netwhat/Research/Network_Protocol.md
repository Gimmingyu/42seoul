Network & Protocol
------------------

-	효율적인 데이터 전송을 위한 장비와 장비간의 연결을 뜻한다.<br><br>
-	이러한 네트워크가 확장되면서, 효율적인 데이터 통신을 위한 규악이 필요해졌다.<br><br>
-	프로토콜이란 네트워크 내에서 데이터 전송시 필요한 규칙 및 약속을 미리 정의한 도구를 의미한다.<br><br>

Encapsulation
-------------

![image](https://user-images.githubusercontent.com/56240505/77378187-a8b3ff00-6db8-11ea-945e-609dd2785151.png)<br><br>

-	PC에서 다른 PC로 데이터를 전송할 때, 데이터를 패키지화하는 과정을 말한다.<br><br>
-	데이터는 초기에 PDU(Protocol Data Unit)라는 형식으로 생성되며, PDU가 다른 PC로 전송될 때 까지 여러번의 패키지 과정이 실시된다.<br><br>
-	위 그림과 같은 통합된 네트워크 환경에서 A Protocol 환경 -> B Protocol 환경으로 데이터를 전송할 경우, A Protocol의 헤더에 IP Protocol의 헤더를 추가하여 전송한다.<br><br>
-	B Protocol 환경에서는 수신한 데이터의 IP Protocol의 헤더를 확인한 뒤, A Protocol의 헤더 정보를 B Protocol로 변경하여 자신의 로컬 환경으로 전송하는 것이다.<br><br>

---

Reference
---------

-	[네트워크란? 프로토콜이란?](https://m.blog.naver.com/hatesunny/220788662088)
