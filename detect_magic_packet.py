#60:e9:aa:17:51:0b - hp laptop 
#60-E9-AA-17-51-0B

from scapy.all import *

def detect_magic_packet(pkt):
    if pkt.haslayer(Ether) and pkt[Ether].dst == 'ff:ff:ff:ff:ff:ff':
        print("Magic packet detected from:", pkt[Ether].src)

# Replace 'eth0' with your network interface
sniff(filter="udp and port 9", prn=detect_magic_packet, iface='wlan0')
