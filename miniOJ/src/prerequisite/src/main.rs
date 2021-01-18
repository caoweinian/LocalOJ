use rusqlite::{Connection, params};

fn main() {
    let conn = Connection::open("db.sqlite3").unwrap();
    conn.execute("create table Go(id integer);", params![]).unwrap();
    
}
