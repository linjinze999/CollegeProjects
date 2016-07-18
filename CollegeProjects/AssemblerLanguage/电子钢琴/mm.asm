DATA SEGMENT 
    DD 122870H,523,587,659,698,784,880,987
    DD 261,293,329,349,392,440,494
    DD 131,147,165,174,196,220,247 
    WELCOME DB '*****WELCOME******',10,13,'$'  
    HIGH1 DB '**HIGH  :1234567**',10,13,'$'   
    MIDDLE2 DB '**MIDDLE:QWERTYU**',10,13,'$'
    LOW3 DB '**LOW   :ASDFGHJ**',10,13,'$'    
    LAST DB '******************',10,13,'$' 
    WRONGTIP DB 'WRONG KEY,PLEASE TRY AGAIN!',10,13,'$'
DATA ENDS

CODE SEGMENT  
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX 
    LEA DX,WELCOME;����
    MOV AH,9
    INT 21H       
    LEA DX,HIGH1
    MOV AH,9
    INT 21H    
    LEA DX,MIDDLE2
    MOV AH,9
    INT 21H      
    LEA DX,LOW3
    MOV AH,9
    INT 21H   
    LEA DX,LAST
    MOV AH,9
    INT 21H
PP: 
    MOV AH,01H;�ȴ���������
    INT 21H  
    CALL ASSIC;ȡ������Ӧ��Ƶ��ֵ��ƫ�Ƶ�ַ    
    CALL SOUND;���÷����ӳ��� 
    JMP PP    ;��������������һ���������� 

ASSIC PROC ;ƫ�Ƶ�ַ������SI��
NUMBER:;����ƫ�Ƶ�ַ
    MOV SI,0
    CMP AL,38H
    JAE LETTER  
    SUB AL,30H
    MOV CX,4      
S1: MOV BL,AL
S2: INC SI
    DEC BL
    JNZ S2
    LOOP S1
    JMP ASSICEND
LETTER:;��ĸƫ�Ƶ�ַ 
Q:  CMP AL,113
    JNE W
    MOV SI,32
    JMP ASSICEND
W:  CMP AL,119
    JNE E
    MOV SI,36
    JMP ASSICEND
E:  CMP AL,101
    JNE R
    MOV SI,40
    JMP ASSICEND 
R:  CMP AL,114
    JNE T
    MOV SI,44
    JMP ASSICEND 
T:  CMP AL,116
    JNE Y
    MOV SI,48
    JMP ASSICEND 
Y:  CMP AL,121
    JNE U
    MOV SI,52
    JMP ASSICEND
U:  CMP AL,117
    JNE A
    MOV SI,56
    JMP ASSICEND
A:  CMP AL,97
    JNE S
    MOV SI,60
    JMP ASSICEND
S:  CMP AL,115
    JNE D
    MOV SI,64
    JMP ASSICEND 
D:  CMP AL,100
    JNE F
    MOV SI,68
    JMP ASSICEND
F:  CMP AL,102
    JNE G
    MOV SI,72
    JMP ASSICEND
G:  CMP AL,103
    JNE H
    MOV SI,76
    JMP ASSICEND  
H:  CMP AL,104
    JNE J
    MOV SI,80
    JMP ASSICEND  
J:  CMP AL,106
    JNE NO
    MOV SI,84
    JMP ASSICEND
NO:   
    MOV DL,0DH   ;����
	MOV AH,02H
	INT 21H
	MOV DL,0AH
	MOV AH,02H
	INT 21H
    LEA DX,WRONGTIP ;������ʾ
    MOV AH,9
    INT 21H
    JMP PP     
ASSICEND:
    RET
ASSIC ENDP

SOUND PROC    ;�����ӳ��� 
    MOV AL,0B6H    ;��ʼ��8254��2�Ŷ�ʱ��
    OUT 43H,AL    
    mov DX,DS:[2]  ;���÷���Ƶ��ֵ
    MOV AX,DS:[0]  
    DIV WORD PTR DS:[SI]                     
    OUT 42H,AL      ;��д��8λ  
    MOV AL,AH  
    OUT 42H,AL      ;��д��8λ 
    OR AL,00000011B ;8255����8254��2�Ŷ�ʱ�� 
    OUT 61H,AL       
    CALL DELAY      ;������ʱ�ӳ���
    AND AL,00000000B;�ָ�����˿�61h��λ
    OUT 61H,AL 
    RET  
SOUND ENDP

DELAY PROC      ;��ʱ�ӳ���
    MOV BX,55000  
    MOV AH,00H
    INT 1AH
    MOV SI,DX
TIME:
    MOV AH,00H
    INT 1AH
    SUB DX,SI
    DEC BX
    JNZ TIME 
    RET
DELAY ENDP
 
OVER:
    MOV AH,4CH
    INT 21H

CODE ENDS
END START
