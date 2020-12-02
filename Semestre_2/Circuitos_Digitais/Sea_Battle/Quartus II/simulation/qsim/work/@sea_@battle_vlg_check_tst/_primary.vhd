library verilog;
use verilog.vl_types.all;
entity Sea_Battle_vlg_check_tst is
    port(
        HIT             : in     vl_logic;
        MISS            : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end Sea_Battle_vlg_check_tst;
