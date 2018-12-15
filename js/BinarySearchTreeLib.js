/**
 * Autor: Leonardo de Almeida Piel
 * Estudante de Engenharia de Computação - Universidade Federal da Grande Dourados
 * Técnico em informática - Instituto Federal do Mato Grosso do Sul
 * Email: leonardo.piel@outlook.com
 * 
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
isEmpty = (node) => { return node === null }
isLeaf = (node) => { return (node.left === null && node.right === null) } // verifica se o nodo é folha


class BinarySearchTree { // Estrutura da árvore binária 
    constructor() {
        this.root = null;
    }

    insert(k) { // algoritmo de inserção de novo nodo
        let newNode = new Node(k); // cria o novo nodo
        if (isEmpty(this.root)) { // se a raiz da árvore for vazia, apenas insira.
            this.root = newNode;
        }
        else {
            let response = this.insertNode(this.root, newNode); // caso a raiz não for vazia: achar lugar certo para inserir. 
            return response;
        }
    }
    insertNode(currentNode, newNode) { // acha nodo certo e insere
        // se a chave do novo nodo for menor, inserir pela esquerda
        if (newNode.key == currentNode.key) return false;
        if (newNode.key < currentNode.key) {
            if (isEmpty(currentNode.left)) { // verificar se a esquerda é nula 
                currentNode.left = newNode;
                return true;
            }
            else
                return this.insertNode(currentNode.left, newNode); // recursivo até achar um espaço vazio
        }
        else {
            if (isEmpty(currentNode.right)) {
                currentNode.right = newNode;
                return true;
            }
            else
                return this.insertNode(currentNode.right, newNode);
        }
    }

    remove(k) { // helper para algoritmo que remove o nodo com a chave k
        if(isEmpty(this.removeNode(this.root, k))) return false;
        return true;
    }

    removeNode(currentNode, k) {
        if (isEmpty(currentNode)) return null; // caso o nodo seja vazia não tem o que remover

        // encontrando as características do nodo
        else if (k < currentNode.key) {
            currentNode.left = this.removeNode(currentNode.left, k);
            return currentNode;
        }
        else if (k > currentNode.key) {
            currentNode.right = this.removeNode(currentNode.right, k);
            return currentNode;
        }
        else {
            // caso o nodo seja folha
            if (isLeaf(currentNode)) {
                currentNode = null;
                return currentNode;
            }
            // caso o nodo tenha filhos apenas à direita
            if (isEmpty(currentNode.left)) {
                currentNode = currentNode.right;
                return currentNode;
            }
            // caso o nodo tenha filhos apenas à esquerda
            if (isEmpty(currentNode.right)) {
                currentNode = currentNode.left;
                return currentNode;
            }
            // caso o nodo tenha os dois filhos
            var aux = this.getMinNode(currentNode.right);
            currentNode.key = aux.key;
            currentNode.right = this.removeNode(currentNode.right, aux.key);
            return currentNode;
        } 
    }
    init(v) { /** inicializa a árvore com o vetor v*/
        let i;
        for (i = 0; i < v.length; i++) {
            this.insert(v[i]);
        }
        return true;
    }

    getMinNode(node) {
        if (isEmpty(node.left)) return node; // condição de parada
        else return this.getMinNode(node.left);
    }

    // sessão de busca recursiva 
    search(k) { // helper
        if (k === this.key) return this; // caso esteja procurando a própria raiz já retorne-a direto.
        let response = this.searchNode(this.root, k); // método que realiza a busca
        return response;
    }
    searchNode(node, k) { // método que realiza busca recursiva de um nodo com a chave k
        if (isEmpty(node)) return null;
        if (k === node.key) return node;
        if (k < node.key) return this.searchNode(node.left, k);
        else return this.searchNode(node.right);
    }
    // fim da sessão de busca

    height() {
        if (isEmpty(this.root)) return -1;
        let h = this.calcHeight(this.root);
        return h;
    }
    calcHeight(node) {
        if (!isEmpty(node)) {
            let l = this.calcHeight(node.left);
            let r = this.calcHeight(node.right);
            if (l < r) return r + 1;
            else return l + 1;
        }
        return -1;
    }

}
v = [5, 4, 3, 2, 8, 6, 7, 9];
tree = new BinarySearchTree();
tree.init(v);


//Referências:
/**
 * https://javascript.info/class 
 * https://www.geeksforgeeks.org/implementation-binary-search-tree-javascript/ */
