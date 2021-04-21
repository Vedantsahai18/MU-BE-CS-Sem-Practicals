# Define options
set val(chan) Channel/WirelessChannel ;# channel type
set val(prop) Propagation/TwoRayGround ;# radio-propagation model
set val(netif) Phy/WirelessPhy ;# network interface type
set val(mac) Mac/802_11 ;# MAC type
set val(ifq) Queue/DropTail/PriQueue ;# interface queue type
set val(ll) LL ;# link layer type
set val(ant) Antenna/OmniAntenna ;# antenna model
set val(ifqlen) 50 ;# max packet in ifq
set val(nn) 50 ;# number of mobilenodes
set val(rp) DSDV ;# routing protocol
set val(x) 1000 ;# X dimension of topography
set val(y) 1000 ;# Y dimension of topography
set val(stop) 150 ;# time of simulation end

set ns [new Simulator]
set tracefd [open simple.tr w]
set namtrace [open simwrls.nam w]

$ns trace-all $tracefd
$ns namtrace-all-wireless $namtrace $val(x) $val(y)

# set up topography object
set topo [new Topography]

$topo load_flatgrid $val(x) $val(y)

create-god $val(nn)



# configure the nodes
$ns node-config -adhocRouting $val(rp) \
-llType $val(ll) \
-macType $val(mac) \
-ifqType $val(ifq) \
-ifqLen $val(ifqlen) \
-antType $val(ant) \
-propType $val(prop) \
-phyType $val(netif) \
-channelType $val(chan) \
-topoInstance $topo \
-agentTrace ON \
-routerTrace ON \
-macTrace OFF \
-movementTrace ON

for {set i 0} {$i < $val(nn) } { incr i } {
set n($i) [$ns node]
}

# Provide initial location of mobilenodes
$n(0) set X_ 347.0
$n(0) set Y_ 3.0
$n(0) set Z_ 0.0

$n(1) set X_ 345.0
$n(1) set Y_ 36.0
$n(1) set Z_ 0.0

$n(2) set X_ 330.0
$n(2) set Y_ 121.0
$n(2) set Z_ 0.0

$n(3) set X_ 316.0
$n(3) set Y_ 152.0
$n(3) set Z_ 0.0

$n(4) set X_ 246.0
$n(4) set Y_ 90.0
$n(4) set Z_ 0.0

$n(5) set X_ 379.0
$n(5) set Y_ 6.0
$n(5) set Z_ 0.0



# Set a TCP connection between n(1) and n(31)
set tcp [new Agent/TCP/Newreno]
$tcp set class_ 2
set sink [new Agent/TCPSink]
$ns attach-agent $n(1) $tcp
$ns attach-agent $n(31) $sink
$ns connect $tcp $sink
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ns at 10.0 "$ftp start"

# Set a TCP connection between n(31) and n(43)
set tcp [new Agent/TCP/Newreno]
$tcp set class_ 2
set sink [new Agent/TCPSink]
$ns attach-agent $n(31) $tcp
$ns attach-agent $n(43) $sink
$ns connect $tcp $sink

#defining heads
$ns at 0.0 "$n(0) label CH"
$ns at 0.0 "$n(1) label Source"
#$ns at 0.0 "$n(2) label N2"



$ns at 10.0 "$n(5) setdest 785.0 228.0 5.0"
$ns at 13.0 "$n(26) setdest 700.0 20.0 5.0"
$ns at 15.0 "$n(14) setdest 115.0 85.0 5.0"

#Color change while moving from one group to another
$ns at 73.0 "$n(2) delete-mark N2"
$ns at 73.0 "$n(2) add-mark N2 pink circle"
$ns at 124.0 "$n(11) delete-mark N11"
$ns at 124.0 "$n(11) add-mark N11 purple circle"
$ns at 103.0 "$n(5) delete-mark N5"
$ns at 103.0 "$n(5) add-mark N5 white circle"
$ns at 87.0 "$n(26) delete-mark N26"
$ns at 87.0 "$n(26) add-mark N26 yellow circle"
$ns at 92.0 "$n(14) delete-mark N14"
$ns at 92.0 "$n(14) add-mark N14 green circle"

# Define node initial position in nam
for {set i 0} {$i < $val(nn)} { incr i } {
# 20 defines the node size for nam
$ns initial_node_pos $n($i) 20
}

# Telling nodes when the simulation ends
for {set i 0} {$i < $val(nn) } { incr i } {
$ns at $val(stop) "$n($i) reset";
}

# ending nam and the simulation
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "stop"
$ns at 150.01 "puts \"end simulation\" ; $ns halt"
proc stop {} {
global ns tracefd namtrace
$ns flush-trace
close $tracefd
close $namtrace
exec nam simwrls.nam &
}

$ns run 
