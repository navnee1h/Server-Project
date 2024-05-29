#pip install wakeonlan scapy

from wakeonlan import send_magic_packet
# Replace the MAC address with the MAC address of the target device
mac_address = 'b0:a7:b9:58:34:26' #my laptop address

# Send the Magic Packet
send_magic_packet(mac_address)
print("Magic packet sent to", mac_address)
