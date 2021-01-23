#[link(name = "m")]
extern{
    fn sqrt(f: f64) -> f64;
}

fn sqrt_wrapper(f: f64) -> f64{
    unsafe{
        sqrt(f)
    }
}

fn main() {
    println!("{}", sqrt_wrapper(2.0));
}