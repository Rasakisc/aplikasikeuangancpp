import serial
import webbrowser
import time
import serial.tools.list_ports
import sys


SERIAL_PORT = "COM5" 
BAUD_RATE = 9600
URL_TUJUAN = "https://pomf2.lain.la/f/5yweet8z.mp4"
URL_TUJUAN2 = "https://bagi2ilmuaditya.blogspot.com/"

print("PENCARIAN PORT")
ports = serial.tools.list_ports.comports()
found_port = False
for port, desc, hwid in sorted(ports):
    print(f"Ditemukan: {port}")
    if port == SERIAL_PORT:
        found_port = True

if not found_port:
    print(f"ERROR: Port {SERIAL_PORT} tidak ditemukan atau sedang digunakan.")
    sys.exit() # Hentikan program jika port tidak ditemukan
    
# --- KONEKSI SERIAL ---
try:
    # Koneksi Serial dengan timeout 1 detik
    arduino = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1) 
    time.sleep(2) # Beri waktu inisialisasi
    print(f"\n Koneksi berhasil ke {SERIAL_PORT}.")
    print(f"Mendengarkan data... Siap untuk scan RFID.")

    # --- PERULANGAN UTAMA ---
    while True:
        # Cek apakah ada data yang menunggu di port serial
        if arduino.in_waiting > 0:
            # Baca baris data, decode ke string, dan hapus spasi/baris baru
            line = arduino.readline().decode(errors="ignore").strip() 
            
            if line: # Pastikan baris tidak kosong
                print(f"Received: {line}")

                if line == "scanned Kartu":
                    print(f"Perintah diterima! Membuka browser ke: {URL_TUJUAN}")
                    webbrowser.open(URL_TUJUAN)
                elif line == "scanned Ganci":
                    print(f"Perintah diterima! membuka browser ke: {URL_TUJUAN2}")     
                    webbrowser.open(URL_TUJUAN2)
                else:
                    print("Perintah tidak dikenali.")
        
        time.sleep(0.01) # 

finally:
    if 'arduino' in locals() and arduino.is_open:
        arduino.close()
        print("\nKoneksi Serial Ditutup.")