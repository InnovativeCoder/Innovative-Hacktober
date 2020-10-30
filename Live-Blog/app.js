//jshint esversion:6

const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const _ = require("lodash");
const mongoose=require("mongoose");

const homeStartingContent = "I am a Web developer and programmer from Ahmedabad, India. I have a passion for web development and love to create for web and mobile devices. I know how to create web applications, to run across devices using the latest technologies available. I am also into competetive programming and love playing with alogrithms and data-structures.This is a personal blog started by me in order to write my thoughts, views and solutions to some major problems, and some latest technological advancements. ";
const aboutContent = "I am a Web developer and programmer from Ahmedabad, India. I am currently pursuing B.E. in Information Technology from Birla Institute of Technology Mesra, Ranchi. I have a passion for web development and love to create for web and mobile devices. I know how to create web applications, to run across devices using the latest technologies available. I am also into competetive programming and love playing with alogrithms and data-structures.";
const contactContent = "The best way to contact me is by email. You can send me an email at adi4adityaraj@gmail.com and I’ll get back to you within 24 hours. Till then keep reading, keep loving. To know more about me, visit: https://adityarajsingh.github.io/";

const app = express();

app.set('view engine', 'ejs');

app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static("public"));


mongoose.connect("mongodb+srv://adityarajsingh:@cluster0-llplo.mongodb.net/test?retryWrites=true/blogDB", {useNewUrlParser: true});

const postSchema={
  title: String,
  content: String
};

const Post = mongoose.model("Post", postSchema);


app.get("/", function(req, res){
  Post.find({},function(err,posts)
  {
 
    res.render("home", {
      startingContent: homeStartingContent,
      posts: posts
      });
  })

});

app.get("/about", function(req, res){
  res.render("about", {aboutContent: aboutContent});
});

app.get("/contact", function(req, res){
  res.render("contact", {contactContent: contactContent});
});

app.get("/compose", function(req, res){
  res.render("compose");
});

app.post("/compose", function(req, res){

  const post = new Post({
    title: req.body.postTitle,
    content: req.body.postBody
  });

  post.save(function(err){
    if(!err){
      res.redirect("/");
    }
  });

});

app.get("/posts/:postId", function(req, res){
  
  const requestedPostId = req.params.postId;

  Post.findOne({_id: requestedPostId}, function(err, post){

    res.render("post", {
 
      title: post.title,
 
      content: post.content
 
    });
 
  });

});

app.listen(process.env.PORT || 3000, function() {
  console.log("Server started on port 3000");
});
