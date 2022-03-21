library verilog;
use verilog.vl_types.all;
entity Sea_Battle_vlg_sample_tst is
    port(
        FIRE            : in     vl_logic;
        N1              : in     vl_logic;
        N2              : in     vl_logic;
        N3              : in     vl_logic;
        N4              : in     vl_logic;
        N5              : in     vl_logic;
        N6              : in     vl_logic;
        N7              : in     vl_logic;
        N8              : in     vl_logic;
        U1              : in     vl_logic;
        U2              : in     vl_logic;
        U3              : in     vl_logic;
        U4              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end Sea_Battle_vlg_sample_tst;
