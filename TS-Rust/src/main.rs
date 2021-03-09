use std::process::Command;
use structopt::StructOpt;
mod lib;
use lib::*;
#[derive(StructOpt)]
#[structopt(name = "Tomorrow-Study Package Manager")]

struct Cli {
    #[structopt(short = "g", long = "get")]
    #[structopt(about = "Gets content directly to System")]
    id: String,
    /*#[structopt(short="l",long="list")]
    #[structopt(about="Lists out available Content")]
    cont_type: String,*/
}

// Content Template
/*
Content{
        name: String::from(""),
        author: String::from(""),
        id: String::from(""),
        url: String::from(""),
};

*/

/*Ex. $ ts <cmd> <tag>*/

fn main() {
    let mut AdvMK = Content {
        name: String::from("Advance Functions (FS)"),
        author: String::from("Mustafif Khan"),
        id: String::from("AMK"),
        url: String::from(
            "https://github.com/MKProj/TomorrowStudy/raw/V1.0.0/tmp/AdvFuncMK/AdvFuncMK.pdf",
        ),
    };

    let mut Calc1MK = Content{
        name: String::from("Calculus 1 (FS)"),
        author: String::from("Mustafif Khan"),
        id: String::from("C1MK"),
        url: String::from(
            "https://github.com/MKProj/TomorrowStudy/raw/V1.0.0/Library/Formula_Sheets/Calc1MK/Calc1MK.pdf"
        ),
};
    let mut FS = Category{cont:[AdvMK, Calc1MK]};
    let args = Cli::from_args();

    let mut i = 0;
    while i < 2 {
        if args.id == FS.cont[i].id {
            let cmd = Command::new("wget")
                .arg(&FS.cont[i].url)
                .output()
                .expect("failed to execute process");
            if cmd.status.success() == true {
                println!("Installed Successfully!")
            }
        }
        i += 1;
    }
}
