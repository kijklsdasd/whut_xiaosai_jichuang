module GPIO (
    input outEn,
    input clk,
    input RSTn,
    input   [3:0]oData,  
    output  [3:0]iData,  
    inout  [3:0]ioPin
);
reg  [3:0]tmp;

always@(posedge clk or negedge RSTn) begin
  if(~RSTn) tmp <= 4'd0;
  else tmp <= ioPin;
end

assign iData = tmp;
assign ioPin = outEn ? oData : 4'bz;

endmodule
