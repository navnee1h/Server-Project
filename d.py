from scapy.all import *

def detect_magic_packet(pkt):
    if pkt.haslayer(Ether) and pkt[Ether].dst == 'ff:ff:ff:ff:ff:ff':
        src_mac = pkt[Ether].src
        src_port = pkt.sport
        print("Magic packet detected from:", src_mac, "on port:", src_port)

# Replace 'wlan0' with your network interface
sniff(filter="udp and port 9", prn=detect_magic_packet, iface='wlan0')
