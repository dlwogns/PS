// 점화식
// 고등학교 수학) 수열
// 1 , 3, 5, 7, ~~~ 
// i번째 홀수를 구하자.  i * 2 -1 = Ai 

// 1 1 2 3 5 ~~~
// A -> 피보나치수 집합 A
// Ai = Ai-1 + Ai-2

// DP -> 여러가지 경우의 점화식을 구하는 것.


// CS -> DP?
// 서울 -> 부산 
// 인천, 수원, 대전, 대구
// 중복되는 연산 자체를 제거해주는 것. -> 메모리를 통해서 -> DP

// 10
// 9 5 3
// 9-> 8 3, 5 -> 4, 3 -> 2 1

// 2*n타일링
// 1 -> 1, 2 -> 2, 3 -> 3, 4 -> 5, 5 -> 8
// 2 * 3
// 세로로 한개를 세우는 방법. 1, 2*2
// 가로로 눕혀서 정사각형모양. 2, 2*1


// 2*4
// 세로 2*3
// 가로 2*2

// 2*N = 2*(N-1) + 2*(N-2)