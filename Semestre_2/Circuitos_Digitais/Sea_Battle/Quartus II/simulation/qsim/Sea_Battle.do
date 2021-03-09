onerror {quit -f}
vlib work
vlog -work work Sea_Battle.vo
vlog -work work Sea_Battle.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.Sea_Battle_vlg_vec_tst
vcd file -direction Sea_Battle.msim.vcd
vcd add -internal Sea_Battle_vlg_vec_tst/*
vcd add -internal Sea_Battle_vlg_vec_tst/i1/*
add wave /*
run -all
