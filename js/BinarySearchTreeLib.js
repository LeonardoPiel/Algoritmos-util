/**
 * Autor: Leonardo de Almeida Piel
 * Estudante de Engenharia de Computação - Universidade Federal da Grande Dourados
 * Técnico em informática - Instituto Federal do Mato Grosso do Sul
 * Email: leonardo.piel@outlook.com
 */


 // Estarei tratando aqui principalmente chaves inteiras,
 // mas poderia ser um tipo: aluno, pessoa, livro etc...
class Node {            
    constructor(k) {
        this.key = k; // chave inteira
        this.left = null; // nodo à esquerda
        this.right = null; // nodo à direita
    }
}
// Maneira "elegante" para verificar se o nodo é nulo. 
// obs: muitos professores cobram esse tipo de formalidade.
isEmpty = (node) => {return node === null}
isLeaf = (node) => {return (node.left === null && node.right === null)} // verifica se o nodo é folha


class BinarySearchTree { // Estrutura da árvore binária 
    constructor() {
        this.root = null; 
    }

    insert(k) { // algoritmo de inserção de novo nodo
        let newNode = new Node(k); // cria o novo nodo
        if(isEmpty(this.root)){ // se a árvore for vazia, apenas insira.
            this.root = newNode;
        }
        else this.insertNode(this.root, newNode); // caso não for vazia: achar nodo certo para inserir.
    }
    
    insertNode(currentNode, newNode){ // acha nodo certo e insere
        // se a chave do novo nodo for menor, inserir pela esquerda
        if(newNode.key < currentNode.key){ 
            if(isEmpty(currentNode.left)) // verificar se a esquerda é nula 
                currentNode.left = newNode;
            else 
                this.insertNode(currentNode.left, newNode); // recursivo até achar um espaço vazio
        }
        else{
            if(isEmpty(currentNode.right))
                currentNode.right = newNode;
            else
                this.insertNode(currentNode.right, newNode);
        }
    }

    remove(k){ // helper para algoritmo que remove o nodo com a chave k
        this.root = this.removeNode(this.root, k);
    }

    removeNode(currentNode, k){ 
        if(isEmpty(currentNode)) return null; // caso a árvore seja vazia não tem o que remover

        // encontrando as características do nodo
        if(k < currentNode.key){
            currentNode.left = this.removeNode(current.left, k);
            return currentNode;
        } 
        if(k > currentNode.key){
            currentNode.left = this.removeNode(currentNode.right, k);
            return currentNode;
        }
        // caso o nodo seja folha
        if(isLeaf(currentNode)) {
            response = currentNode;
            currentNode = null;
            return currentNode;
        }
        // caso o nodo tenha filhos apenas à direita
        if(isEmpty(currentNode.left)){
            currentNode = currentNode.right;
            return currentNode;
        }
        // caso o nodo tenha filhos apenas à esquerda
        if(isEmpty(currentNode.right)){
            currentNode = currentNode.left;
            return currentNode;
        }
        // caso o nodo tenha os dois filhos
        var aux = this.getMinNode(currentNode.right);
        currentNode.key = aux.key;

        currentNode.right = this.removeNode(currentNode.right, aux.key);
        return currentNode;
    }
    getMinNode(node){
        if(isEmpty(node.left)) return node; // condição de parada
        else return getMinNode(node.left);
    }
}


//Referências:
/**
 * https://javascript.info/class 
 * https://www.geeksforgeeks.org/implementation-binary-search-tree-javascript/ */
