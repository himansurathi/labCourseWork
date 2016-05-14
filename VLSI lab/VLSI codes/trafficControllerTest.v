`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   07:41:36 03/14/2016
// Design Name:   trafficLightController
// Module Name:   F:/VLSI Lab/trafficController/trafficControllerTest.v
// Project Name:  trafficController
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: trafficLightController
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module trafficControllerTest;

	// Inputs
	reg clk;
	reg clr;

	// Outputs
	wire [5:0] lights;
	reg [4:0] i;
	// Instantiate the Unit Under Test (UUT)
	trafficLightController uut (
		.clk(clk), 
		.clr(clr), 
		.lights(lights)
	);

	initial begin
		clr = 1;
		clk=1;
		i=5'b00000;
		#10 
		clr=0;
		for(i=0;i<=19;i=i+1)
		begin
			clk=~clk;
			#5;
		end
		$stop;
	end
endmodule