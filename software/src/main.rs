use std::str;
use std::time::Duration;
use textplots::{Chart, Plot, Shape};
use std::error::Error;
use std::fs::File;
use std::io::prelude::*;

fn main() {
    let mut points = vec![(0.0, 0.0)];
    let mut file = File::create("data.txt").unwrap();
    let ports = serialport::available_ports().expect("No ports found!");
    let portname = &ports[0].port_name;
    let mut port = serialport::new(portname, 115_200)
        .timeout(Duration::from_millis(10))
        .open()
        .expect("Failed to open port");
    let mut counter = 1.0;

    loop {
        let mut serial_buf: Vec<u8> = vec![0; 16];
        port.read(serial_buf.as_mut_slice());
        if (serial_buf[0] != 0 && serial_buf[1] != 0 && serial_buf[3] != 0) {
            if(points.len() > 4) {
                let mut points = vec![(0.0, 0.0)];

            }
        
            let sparkle_heart = str::from_utf8(&serial_buf).unwrap();
            let output: Vec<&str> = sparkle_heart.split('\r').collect();
            let f = output[0].parse::<f32>().unwrap();
            counter = counter + 1.0;
            points.insert(points.len(), (counter, f));
            Chart::new(100, 100, -50.0, 50.0).lineplot(&Shape::Lines(&points)).display();
            file.write_all(format!("{}\n",output[0]).as_bytes()).unwrap();
        }
    }
}
