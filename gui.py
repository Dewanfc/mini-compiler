import tkinter as tk
from tkinter import scrolledtext, messagebox
import subprocess
import os
from PIL import Image, ImageTk

def compile_code():
    # 1. Get code from the text editor
    source_code = editor.get("1.0", tk.END)
    
    # 2. Save it to a temporary file
    with open("gui_test.txt", "w") as f:
        f.write(source_code)
    
    # 3. Run the C compiler
    try:
        # Hide the terminal window popup on Windows
        startupinfo = subprocess.STARTUPINFO()
        startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
        
        result = subprocess.run(
            ["compiler.exe", "gui_test.txt"], 
            capture_output=True, 
            text=True,
            startupinfo=startupinfo
        )
        
        # 4. Show the TAC output
        console.config(state=tk.NORMAL)
        console.delete("1.0", tk.END)
        console.insert(tk.END, result.stdout)
        if result.stderr:
            console.insert(tk.END, "\nERRORS:\n" + result.stderr)
        console.config(state=tk.DISABLED)
        
        # 5. Load and display the AST image
        if os.path.exists("ast.png"):
            img = Image.open("ast.png")
            # Resize image to fit the panel while maintaining aspect ratio
            img.thumbnail((500, 600)) 
            img_tk = ImageTk.PhotoImage(img)
            ast_label.config(image=img_tk)
            ast_label.image = img_tk # Keep a reference so it doesn't get garbage collected
            
    except Exception as e:
        messagebox.showerror("Execution Error", f"Could not run compiler.exe: {e}\nDid you run 'mingw32-make' first?")

# --- GUI Setup ---
root = tk.Tk()
root.title("Compiler Construction Lab - Visual IDE")
root.geometry("1000x650")
root.configure(padx=10, pady=10)

# Left Frame: Editor & Console
left_frame = tk.Frame(root)
left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

tk.Label(left_frame, text="Source Code:", font=("Arial", 10, "bold")).pack(anchor=tk.W)
editor = scrolledtext.ScrolledText(left_frame, height=20, width=50, font=("Courier", 11))
editor.pack(fill=tk.BOTH, expand=True, pady=(0, 10))

# Insert default test code
default_code = """int sum(int a, int b) {\n    return a + b;\n}\n\nint main() {\n    int x;\n    x = 10 + 20;\n    print sum(x, 5);\n}"""
editor.insert(tk.END, default_code)

compile_btn = tk.Button(left_frame, text="⚙️ Compile Code", bg="#4CAF50", fg="white", font=("Arial", 12, "bold"), command=compile_code)
compile_btn.pack(fill=tk.X, pady=5)

tk.Label(left_frame, text="Compiler Output (TAC):", font=("Arial", 10, "bold")).pack(anchor=tk.W)
console = scrolledtext.ScrolledText(left_frame, height=12, width=50, bg="#1e1e1e", fg="#00ff00", font=("Consolas", 10))
console.pack(fill=tk.BOTH, expand=True)
console.config(state=tk.DISABLED)

# Right Frame: AST Visualization
right_frame = tk.Frame(root, width=500)
right_frame.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=(10, 0))
right_frame.pack_propagate(False) # Prevent shrinking

tk.Label(right_frame, text="Abstract Syntax Tree (AST):", font=("Arial", 10, "bold")).pack(anchor=tk.N)
ast_label = tk.Label(right_frame, text="Compile code to view AST", bg="#e0e0e0", relief="sunken")
ast_label.pack(fill=tk.BOTH, expand=True, pady=5)

root.mainloop()