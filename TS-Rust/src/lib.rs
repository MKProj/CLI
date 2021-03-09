pub struct Content {
    pub name: String,
    pub author: String,
    pub id: String,
    pub url: String,
}

pub struct Category {
    pub cont: [Content; 2],
}
