module mux4to1(s, d0, d1, d2, d3, z);
    input [1:0] s;
    input d0, d1, d2, d3;
    output reg z;

    always @(*) begin
        case (s)
            0 : z = d0;
            1 : z = d1;
            2 : z = d2; 
            default: z = d3; 
        endcase
    end
endmodule