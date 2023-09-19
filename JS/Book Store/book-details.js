var contentContainer = document.querySelector("main");
var queryString = window.location.search;
var urlParams = new URLSearchParams(queryString);
var detailsID = urlParams.get("id");
var wrapper = document.querySelector(".wrapper");
var bookImage = document.querySelector(".hero-section img");
var bookTitle = document.querySelector(".book-title");
var bookdescription = document.querySelector(".book-description");
var authorsHeading = document.querySelector("h2");
var authorsList = document.querySelector(".authors ul");
var publisher = document.querySelector(".publisher");
var publisherValue = document.querySelector(".publisher span");
var publishDate = document.querySelector(".date");
var publishDateValue = document.querySelector(".date span");
var addToCartButton = document.querySelector(".hero-section button");
var countText = document.querySelector(".count");
var home = document.querySelector(".home");
var count = 0;
// playing animation
function loader() {
  wrapper.classList.add("loader");
}
window.addEventListener("load", loader);

// Creating new XMLHttpRequest
var xhr = new XMLHttpRequest();

xhr.open("GET", `https://www.googleapis.com/books/v1/volumes/${detailsID}`);

xhr.send();

// Rendering document based on the response
xhr.onerror = function () {
  wrapper.classList.remove("loader");
  window.removeEventListener("load", loader);
  wrapper.style.height = "500px";
  wrapper.innerText = "network down or invalid URL";
  wrapper.style.fontSize = "20px";
  wrapper.style.color = "red";
  wrapper.style.textAlign = "center";
};

xhr.onload = function () {
  wrapper.classList.remove("loader");
  window.removeEventListener("load", loader);
  renderBook(JSON.parse(xhr.response));
};

function renderBook(book) {
  if (book.volumeInfo.imageLinks && book.volumeInfo.imageLinks.thumbnail) {
    bookImage.setAttribute("src", `${book.volumeInfo.imageLinks.thumbnail}`);
  } else {
    bookImage.setAttribute("src", `./assets/noImage.jpg`);
  }
  if (book.volumeInfo && book.volumeInfo.description) {
    bookdescription.innerHTML = book.volumeInfo.description;
  } else {
    bookdescription.innerText = "Description: N/A";
    bookdescription.style.marginTop = "50px";
    bookdescription.style.fontWeight = "bold";
  }
  if (book.volumeInfo && book.volumeInfo.title) {
    bookTitle.innerText = book.volumeInfo.title;
  } else {
    bookTitle.style.marginTop = "50px";
    bookTitle.innerText = "Title: N/A";
  }

  if (book.volumeInfo && book.volumeInfo.authors) {
    authorsHeading.innerText = "Authors";
    book.volumeInfo.authors.forEach(function (authorName) {
      var author = document.createElement("li");
      author.innerText = authorName;
      authorsList.appendChild(author);
    });
  } else {
    var author = document.createElement("li");
    author.innerText = "N/A";
    authorsList.appendChild(author);
  }

  if (book.volumeInfo && book.volumeInfo.publisher) {
    publisher.innerHTML = `Publisher: <span>${book.volumeInfo.publisher}</span>`;
  } else {
    publisher.innerHTML = `Publisher: <span>N/A</span>`;
  }
  if (book.volumeInfo && book.volumeInfo.publishedDate) {
    publishDate.innerHTML = `Published Date: <span>${book.volumeInfo.publishedDate}</span>`;
  } else {
    publishDate.innerHTML = `Published Date: <span>N/A</span>`;
  }
  // add to cart button
  addToCartButton.innerText = "Add to Cart";
  addToCartButton.setAttribute("id", "CTA");

  // add footer
  creatFooter();
}
// Function to create a footer
function creatFooter() {
  var footers = document.querySelectorAll("footer");
  if (footers.length > 0) {
    return;
  } else {
    var footer = document.createElement("footer");
    contentContainer.appendChild(footer);
    footer.style.display = "flex";
    contentContainer.style.height = "500px";
    footer.style.alignItems = "center";
    footer.style.justifyContent = "center";
    footer.style.gap = "20px";
    footer.style.marginTop = "10px";

    footer.innerHTML = `<span><a href="https://github.com/Genesis-o-0" target="_blank"><i class="fa-brands fa-github fa-xl" style="color: #ffffff;"></i></a></span><span><a href="https://www.linkedin.com/in/mohamed-lotfy007/" target="_blank"><i class="fa-brands fa-linkedin fa-xl" style="color: #ffffff;"></i></a></span>`;
  }
}

addToCartButton.addEventListener("click", function () {
  count += 1;
  countText.innerText = count;
});

home.addEventListener("click", function () {
  if (!countText.innerText) {
    return;
  } else {
    window.open(`index.html?count=${countText.innerText}`);
  }
});
