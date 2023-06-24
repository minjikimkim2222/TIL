1.수식의 괄호쌍이란? 
===
주어진 괄호 문자열이 올바른지?
![image](https://github.com/minjikimkim2222/study/assets/96869808/d31f26ad-69c0-4b0e-a615-f0eb84852cd8)
</br>

2.관찰을 통해 얻은 해결법
===
idea : "문자열을 앞에서부터 읽어나갈 때, **닫는** 괄호는 남아있는 괄호 중에서 **가장 최근**에 들어온 
여는 괄호와 짝을 지어 없애버리는 명령어" -> **LILO 성질이 묻음!!** </br>
![image](https://github.com/minjikimkim2222/study/assets/96869808/dbc6d23c-18f0-4907-b505-84f0d77b1257)
