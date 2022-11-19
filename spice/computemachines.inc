.model mnmos nmos level=8 

.model mpmos pmos level=8

*
VS	1	0	AC	1  PWL(0US 0V  0.01US 1V)
XOP	1 0	3	OPAMP1
RL	3	0	1K
*
* OPAMP MACRO MODEL, SINGLE-POLE 
* connections:      non-inverting input
*                   |   inverting input
*                   |   |   output
*                   |   |   |
.SUBCKT OPAMP1      1   2   6
* INPUT IMPEDANCE
RIN	1	2	10MEG
* DC GAIN=100K AND POLE1=100HZ
* UNITY GAIN = DCGAIN X POLE1 = 10MHZ
EGAIN	3 0	1 2	100K
RP1	3	4	1K
CP1	4	0	1.5915UF
* OUTPUT BUFFER AND RESISTANCE
EBUFFER	5 0	4 0	1
ROUT	5	6	10
.ENDS
* 
* ANALYSIS
.AC 	DEC 	5 1 100MEG
*.TRAN 	0.05US  2US
* VIEW RESULTS
.PROBE
.END


.model 2N3904 NPN(IS=1E-14 VAF=100
+  Bf=300 IKF=0.4 XTB=1.5 BR=4
+  CJC=4E-12  CJE=8E-12 RB=20 RC=0.1 RE=0.1
+  TR=250E-9  TF=350E-12 ITF=1 VTF=2 XTF=3 mfg=Philips)

.model 2N3906 PNP(IS=1E-14 VAF=100
+  BF=200 IKF=0.4 XTB=1.5 BR=4
+  CJC=4.5E-12 CJE=10E-12 RB=20 RC=0.1 RE=0.1
+  TR=250E-9   TF=350E-12 ITF=1 VTF=2 XTF=3 mfg=Philips)

