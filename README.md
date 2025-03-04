# **ShellBOT – Local Chatbot Project**

## **Overview**

ShellBOT is a command-line chatbot client that sends user prompts to a locally hosted LLM (Large Language Model) server. The client uses **libcurl** to communicate via HTTP and parses JSON responses using **cJSON**. It was tested using **LM Studio** running the **deepseek-r1-distill-llama-8b** model.

### **Key Points**

- Sends prompts via POST requests to a configurable endpoint.
- Parses returned JSON for generated text.

---

## **Project Files**

```
├── api.c          # Contains the send_query function that performs HTTP requests
├── api.h          # Header for api.c
├── json_parser.c  # Contains functions for JSON parsing (via cJSON)
├── json_parser.h  # Header for json_parser.c
├── main.c         # Main CLI application that reads user input and calls send_query
├── Makefile       # Script for building the project
├── LICENSE        # License file
└── README.md      # Documentation
```

**LM Studio with deepseek-r1-distill-llama-8b**  
If you are using LM Studio locally, it can host the **deepseek-r1-distill-llama-8b** model, exposing an endpoint on `http://localhost:8080/v1/completions`. This project’s default endpoint is set to that URL. You can change it by modifying `API_ENDPOINT` in **api.c**.

---

## **Dependencies**

- **libcurl** (development headers)
- **cJSON** (development headers)
- A local LLM endpoint (e.g., **LM Studio** hosting **deepseek-r1-distill-llama-8b** on port 8080)

On Debian/Ubuntu systems, these can be installed with:
```bash
sudo apt-get update
sudo apt-get install -y libcurl4-openssl-dev libcjson-dev
```

---

## **Build and Run**

1. **Install Dependencies**  
   ```bash
   make install_deps
   ```
   Installs cURL and cJSON headers on Debian/Ubuntu.

2. **Build**  
   ```bash
   make
   ```
   Produces an executable named `shellbot`.

3. **Run**  
   ```bash
   ./shellbot
   ```
   - Enter prompts at the `>` prompt.  
   - The request is sent to the address stored in `API_ENDPOINT` (by default `http://localhost:8080/v1/completions`).  
   - Type `exit` or `q` to quit.

4. **Clean**  
   ```bash
   make clean
   ```

---

## **Modifying the Endpoint**

The server link is stored in the variable `API_ENDPOINT` in **api.c**. Update its default value to point to another address if needed:
```c
char* API_ENDPOINT = "http://localhost:8080/v1/completions";
```

---

## **Sample Interaction**

If LM Studio (hosting the **deepseek-r1-distill-llama-8b** model) is running on `localhost:8080`:

```bash
$ ./shellbot
> Hello, how are you?
Chatbot: I'm doing well, thank you! How can I help?
> What is the capital of France?
Chatbot: The capital of France is Paris.
> q
```

---

## **License**

See the `LICENSE` file for the terms and conditions of using or distributing this code.

---

## **Author**

- **Olaf Naruszko**
