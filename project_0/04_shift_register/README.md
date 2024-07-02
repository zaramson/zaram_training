# Shift Register
## Operation Principle
- Serial-to-Parallel converter: i_Sin to o_Qout[0:N-1] 
	- i_Load = 1

- Parallel-to-Serial converter: i_D[0:N-1] to o_Sout
	- First CLK cycle i_Load = 1, Other cycle i_Load = 0

![Waveform0](./32shift_register.png)


## Verilog Code
###DUT
```verilog

```


### Testbench
```verilog



```

## Simulation Result
- Serial-to-Parallel
![Waveform0](./.png)


- Parallel-to-Serial 
![Waveform0](./.png)
