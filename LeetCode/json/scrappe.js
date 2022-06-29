// From a page like 

data = Array.from(document.querySelectorAll(".overview-tables-base > div")).map(item => ({
    "title": item.querySelector(".chapter-title").innerText, 
    "problems": Array.from(item.querySelectorAll(".title span")).map(item => item.innerText)
}))


saveDataAsFile(data, "adobe.json")


// From problem list

data = Array.from(document.querySelectorAll("div.odd\\:bg-layer-1")).map((item, idx) => ({
    "id": idx + 1, 
    "link": item.querySelector("div:nth-child(2) a").href, 
    "problem": item.querySelector("div:nth-child(2)").innerText, 
    "acceptance": item.querySelector("div:nth-child(4)").innerText, 
    "difficulty": item.querySelector("div:nth-child(5)").innerText,
    "frequency": item.querySelector("div:nth-child(6)  div:nth-child(2)")?.style.width
}))

saveDataAsFile(data, "problems-by-frequency-1.json")